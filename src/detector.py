"""
Core shape detection for the PennAiR software challenge.

Approach
--------
Rather than keying on a specific background colour (e.g. "remove the green"),
we key on *texture*.  The targets are solid, flat-shaded shapes; natural
backgrounds like grass are visually busy.  So we build a local-contrast map and
call the smooth regions "shape".

    1. Denoise, then measure local standard deviation in a sliding window over
       each colour channel (computed with box filters, so it is O(1) per pixel
       regardless of window size).
    2. Threshold against the frame's OWN median busyness, which is what makes
       this background agnostic -- nothing in here says "green".
    3. Clean up morphologically, but *gently*: where two shapes touch, the
       colour step between them registers as texture, and that thin gap is the
       only thing separating them.  Aggressive closing welds them together.
    4. Re-grow each blob to its true colour edge, bounded to a narrow band so
       growth cannot escape into a similarly-coloured background.
    5. Filter by size and solidity, then take centers from image moments.

Video runs at 1080p, so the mask is computed on a downscaled copy and the
per-shape refinement happens at full resolution inside small ROIs.  That keeps
outline accuracy while staying comfortably real-time.
"""

from dataclasses import dataclass
import cv2
import numpy as np


@dataclass
class Shape:
    """One detected shape."""
    contour: np.ndarray          # Nx1x2 int32, as OpenCV likes it
    center: tuple                # (cx, cy) in pixels
    area: float
    clipped: bool = False        # touches the frame border (partially visible)

    @property
    def circularity(self) -> float:
        """4*pi*A/P^2 -- 1.0 for a perfect circle, lower for polygons."""
        peri = cv2.arcLength(self.contour, True)
        return 4 * np.pi * self.area / (peri ** 2) if peri > 0 else 0.0

    @property
    def vertices(self) -> int:
        """Corner count of the polygon approximation (3=triangle, etc.).

        A slightly rounded corner makes approxPolyDP emit two or three vertices
        a few pixels apart, which turns a triangle into a "pentagon".  So after
        approximating we fuse any vertices closer together than 8% of the
        perimeter -- real polygon corners are far further apart than that.
        """
        peri = cv2.arcLength(self.contour, True)
        if peri <= 0:
            return 0
        approx = cv2.approxPolyDP(self.contour, 0.02 * peri, True)
        pts = approx.reshape(-1, 2).astype(np.float32)
        if len(pts) < 3:
            return len(pts)

        min_gap = 0.08 * peri
        keep = [pts[0]]
        for p in pts[1:]:
            if np.linalg.norm(p - keep[-1]) > min_gap:
                keep.append(p)
        # The contour is closed, so check the wrap-around pair too.
        if len(keep) > 1 and np.linalg.norm(keep[0] - keep[-1]) <= min_gap:
            keep.pop()
        return len(keep)

    def name(self) -> str:
        # A shape running off the edge of frame is a fragment, not a polygon --
        # naming it from its vertex count would just be wrong.
        if self.clipped:
            return "shape (clipped)"
        v = self.vertices
        if v == 3:
            return "triangle"
        if v == 4:
            (_, _), (w, h), _ = cv2.minAreaRect(self.contour)
            if min(w, h) > 0 and 0.9 <= max(w, h) / max(min(w, h), 1e-6) <= 1.1:
                return "square"
            return "quadrilateral"
        if v == 5:
            return "pentagon"
        # Beyond 5 corners, polygon approximation gets unreliable on a circle's
        # smooth edge, so fall back to circularity.  A regular hexagon scores
        # ~0.91 and a circle ~1.0, hence the cut at 0.93.
        if self.circularity > 0.93:
            return "circle"
        return f"{v}-gon"


class ShapeDetector:
    """Detects solid shapes against a textured background."""

    def __init__(
        self,
        window: int = 11,                # local-contrast window (px)
        texture_ratio: float = 0.35,     # smooth if busyness < ratio * median
        min_area_frac: float = 0.0015,   # ignore specks below this frac of frame
        max_area_frac: float = 0.40,     # ignore blobs bigger than this (bg)
        min_solidity: float = 0.85,      # area / convex-hull area
        smooth_eps_frac: float = 0.004,  # contour smoothing, frac of perimeter
        proc_width: int = 960,           # analyse at this width, for speed
    ):
        self.window = window
        self.texture_ratio = texture_ratio
        self.min_area_frac = min_area_frac
        self.max_area_frac = max_area_frac
        self.min_solidity = min_solidity
        self.smooth_eps_frac = smooth_eps_frac
        self.proc_width = proc_width

    # ------------------------------------------------------------ busyness
    def _busy_map(self, img: np.ndarray) -> np.ndarray:
        """Per-pixel local standard deviation, maxed across colour channels."""
        # Median blur kills grass speckle without softening real shape edges.
        f = cv2.medianBlur(img, 5).astype(np.float32)
        k = (self.window, self.window)
        # Var(X) = E[X^2] - E[X]^2, per channel, via box filter -> O(1)/pixel.
        mean = cv2.blur(f, k)
        mean_sq = cv2.blur(f * f, k)
        std = np.sqrt(np.maximum(mean_sq - mean * mean, 0.0))
        # A pixel is "busy" if ANY channel is busy.
        return std.max(axis=2)

    # ---------------------------------------------------------------- mask
    def texture_mask(self, img: np.ndarray) -> np.ndarray:
        """Binary mask: 255 where the image is locally smooth."""
        busy = self._busy_map(img)
        # The median is a robust estimate of "how textured is the background
        # here", so the cut adapts to grass, gravel, carpet, whatever.
        # (Otsu is wrong for this: the background dominates the histogram, so
        # Otsu ends up bisecting the background instead of separating it from
        # the shapes.)
        thresh = max(self.texture_ratio * float(np.median(busy)), 1e-3)
        mask = (busy < thresh).astype(np.uint8) * 255

        # Open to drop stray smooth pixels in the grass.  Close only gently --
        # a 15x15 close welds touching shapes into one blob, because the colour
        # step between them is exactly the thin busy line that separates them.
        mask = cv2.morphologyEx(
            mask, cv2.MORPH_OPEN,
            cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5)))
        mask = cv2.morphologyEx(
            mask, cv2.MORPH_CLOSE,
            cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (7, 7)))
        return mask

    # ------------------------------------------------------------- refine
    def _refine(self, frame: np.ndarray, seed: np.ndarray,
                band_px: int) -> np.ndarray:
        """Grow a seed region out to the shape's true colour boundary.

        The local-contrast window pulls the mask ~window/2 px inside the real
        edge, so the raw outline is a shrunken copy of the shape.  We re-grow
        it using the seed's own colour.

        Two guards keep this honest:
          * the tolerance scales with the seed's own colour spread, so a flat
            fill stays tight while a gradient fill gets room to breathe;
          * growth is confined to `band_px` around the seed.  Without that
            bound, a green shape on green grass floods its whole ROI -- colour
            alone cannot tell them apart, only texture can.

        `band_px` has to cover the seed's inset, which is (window/2) scaled up
        from the analysis resolution.  Too tight and corners stay rounded (a
        triangle then approximates to five vertices); too loose and the leash
        stops doing its job.
        """
        H, W = frame.shape[:2]
        x, y, w, h = cv2.boundingRect(seed)
        pad = 2 * band_px
        x0, y0 = max(x - pad, 0), max(y - pad, 0)
        x1, y1 = min(x + w + pad, W), min(y + h + pad, H)

        roi = frame[y0:y1, x0:x1]
        roi_seed = seed[y0:y1, x0:x1]

        # CIE-Lab so colour distance is roughly perceptual.
        lab = cv2.cvtColor(cv2.medianBlur(roi, 5), cv2.COLOR_BGR2LAB).astype(np.float32)
        seed_px = lab[roi_seed > 0]
        if len(seed_px) < 10:
            return None

        med = np.median(seed_px, axis=0)
        spread = float(np.percentile(np.linalg.norm(seed_px - med, axis=1), 90))
        tol = min(max(12.0, 2.0 * spread), 60.0)

        dist = np.linalg.norm(lab - med, axis=2)
        # Geometric leash: we only ever need to recover the window-sized inset.
        band = cv2.dilate(
            roi_seed,
            cv2.getStructuringElement(cv2.MORPH_ELLIPSE,
                                      (2 * band_px + 1, 2 * band_px + 1)))
        grown = ((dist <= tol) & (band > 0)).astype(np.uint8) * 255
        grown = cv2.morphologyEx(
            grown, cv2.MORPH_CLOSE,
            cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5)))

        # Keep only the blob that actually contains our seed.
        n, labels = cv2.connectedComponents(grown)
        hit = np.bincount(labels[roi_seed > 0], minlength=n)
        hit[0] = 0
        if hit.max() == 0:
            return None
        keep = ((labels == int(hit.argmax())).astype(np.uint8)) * 255

        cs, _ = cv2.findContours(keep, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        if not cs:
            return None
        best = max(cs, key=cv2.contourArea)
        best[:, :, 0] += x0          # ROI -> full-frame coordinates
        best[:, :, 1] += y0
        return best

    # ------------------------------------------------------------- detect
    def detect(self, frame: np.ndarray) -> list:
        H, W = frame.shape[:2]
        frame_area = float(H * W)

        # Analyse a downscaled copy: the mask only has to say *where* shapes
        # are, and 1080p costs 4x the work for no extra localisation value.
        scale = min(1.0, self.proc_width / float(W))
        small = (cv2.resize(frame, None, fx=scale, fy=scale, interpolation=cv2.INTER_AREA)
                 if scale < 1.0 else frame)

        mask = self.texture_mask(small)
        # RETR_EXTERNAL: we want whole shapes, not holes inside them.
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        small_area = float(small.shape[0] * small.shape[1])
        shapes = []
        for c in contours:
            if not (self.min_area_frac * small_area <= cv2.contourArea(c)
                    <= self.max_area_frac * small_area):
                continue

            # Back to full resolution, where the refinement can be precise.
            full_c = (c.astype(np.float32) / scale).astype(np.int32)
            seed = np.zeros((H, W), np.uint8)
            cv2.drawContours(seed, [full_c], -1, 255, -1)

            # Seed inset is ~window/2 at analysis scale; allow twice that
            # back at full resolution so corners can be recovered.
            band_px = max(int(round(self.window / scale)), self.window)
            refined = self._refine(frame, seed, band_px)
            c_out = refined if refined is not None else full_c
            area = cv2.contourArea(c_out)
            if not (self.min_area_frac * frame_area <= area
                    <= self.max_area_frac * frame_area):
                continue

            # Solid convex-ish blobs only; rejects ragged texture patches.
            hull_area = cv2.contourArea(cv2.convexHull(c_out))
            if hull_area <= 0 or area / hull_area < self.min_solidity:
                continue

            # Smooth the jagged pixel staircase into clean polygon edges.
            peri = cv2.arcLength(c_out, True)
            c_out = cv2.approxPolyDP(c_out, self.smooth_eps_frac * peri, True)

            m = cv2.moments(c_out)
            if m["m00"] == 0:
                continue
            cx = int(round(m["m10"] / m["m00"]))
            cy = int(round(m["m01"] / m["m00"]))

            bx, by, bw, bh = cv2.boundingRect(c_out)
            clipped = bx <= 1 or by <= 1 or bx + bw >= W - 1 or by + bh >= H - 1

            shapes.append(Shape(contour=c_out, center=(cx, cy),
                                area=area, clipped=clipped))

        # Biggest first, so output ordering is stable frame to frame.
        shapes.sort(key=lambda s: s.area, reverse=True)
        return shapes


# ------------------------------------------------------------------ draw
def annotate(frame: np.ndarray, shapes: list, label: bool = True) -> np.ndarray:
    """Draw outlines, centers and coordinate labels onto a copy of `frame`."""
    out = frame.copy()
    for s in shapes:
        cv2.drawContours(out, [s.contour], -1, (0, 0, 255), 3)
        cx, cy = s.center
        cv2.drawMarker(out, (cx, cy), (255, 255, 255),
                       cv2.MARKER_CROSS, markerSize=18, thickness=3)
        cv2.circle(out, (cx, cy), 5, (0, 0, 255), -1)
        if label:
            text = f"{s.name()} ({cx}, {cy})"
            font, scale, thick = cv2.FONT_HERSHEY_SIMPLEX, 0.55, 1
            (tw, th), _ = cv2.getTextSize(text, font, scale, thick)
            # Keep the label on screen even for shapes near an edge.
            tx = min(max(cx + 12, 2), out.shape[1] - tw - 2)
            ty = max(cy - 12, th + 2)
            # Dark outline under white text keeps it readable on any background.
            cv2.putText(out, text, (tx, ty), font, scale, (0, 0, 0), 4, cv2.LINE_AA)
            cv2.putText(out, text, (tx, ty), font, scale, (255, 255, 255), thick, cv2.LINE_AA)
    return out
