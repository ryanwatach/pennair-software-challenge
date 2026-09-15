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
    2. Otsu-threshold that map.  Otsu picks the split point from the image
       itself, which is what makes this background agnostic -- nothing in here
       says "green".
    3. Morphologically clean up, fill holes, and keep components whose size and
       shape look like a target.
    4. Smooth each surviving contour and take its centroid from image moments.
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

    @property
    def vertices(self) -> int:
        """Corner count of the polygon approximation (3=triangle, etc.)."""
        peri = cv2.arcLength(self.contour, True)
        approx = cv2.approxPolyDP(self.contour, 0.02 * peri, True)
        return len(approx)

    def name(self) -> str:
        v = self.vertices
        if v == 3:
            return "triangle"
        if v == 4:
            # square vs. other quad, from the min-area rect aspect ratio
            (_, _), (w, h), _ = cv2.minAreaRect(self.contour)
            if min(w, h) > 0 and 0.9 <= w / h <= 1.1:
                return "square"
            return "quadrilateral"
        if v == 5:
            return "pentagon"
        # high vertex count + near-perfect circularity -> circle
        peri = cv2.arcLength(self.contour, True)
        if peri > 0 and 4 * np.pi * self.area / (peri ** 2) > 0.80:
            return "circle"
        return f"{v}-gon"


class ShapeDetector:
    """Detects solid shapes against a textured background."""

    def __init__(
        self,
        window: int = 11,          # local-contrast window (px)
        texture_ratio: float = 0.35,     # smooth if busyness < ratio * median
        min_area_frac: float = 0.0015,   # ignore specks below this frac of frame
        max_area_frac: float = 0.40,     # ignore blobs bigger than this (bg)
        min_solidity: float = 0.85,      # area / convex-hull area
        smooth_eps_frac: float = 0.004,  # contour smoothing, frac of perimeter
    ):
        self.window = window
        self.texture_ratio = texture_ratio
        self.min_area_frac = min_area_frac
        self.max_area_frac = max_area_frac
        self.min_solidity = min_solidity
        self.smooth_eps_frac = smooth_eps_frac

    # ---------------------------------------------------------------- mask
    def texture_mask(self, frame: np.ndarray) -> np.ndarray:
        """Binary mask: 255 where the image is locally smooth."""
        # Median blur kills grass speckle without softening real shape edges.
        blurred = cv2.medianBlur(frame, 5)
        f = blurred.astype(np.float32)

        k = (self.window, self.window)
        # Var(X) = E[X^2] - E[X]^2, per channel, via box filter.
        mean = cv2.blur(f, k)
        mean_sq = cv2.blur(f * f, k)
        var = np.maximum(mean_sq - mean * mean, 0.0)
        std = np.sqrt(var)

        # A pixel is "busy" if ANY channel is busy -> max across channels.
        busy = std.max(axis=2)

        # Threshold relative to the image's OWN median busyness.  The median is
        # a robust estimate of "how textured is the background here", so the cut
        # adapts to grass, gravel, carpet, whatever -- we never name a colour.
        # (Otsu is wrong here: the background dominates the histogram, so Otsu
        # ends up bisecting the background instead of separating it from the
        # shapes.)
        thresh = max(self.texture_ratio * float(np.median(busy)), 1e-3)
        mask = (busy < thresh).astype(np.uint8) * 255

        # Clean up: drop stray smooth pixels, then seal the shape interiors.
        open_k = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5))
        close_k = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (15, 15))
        mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, open_k, iterations=1)
        mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, close_k, iterations=2)
        return mask

    # ------------------------------------------------------------- refine
    def _refine(self, frame: np.ndarray, seed: np.ndarray) -> np.ndarray:
        """Grow a seed region out to the shape's true colour boundary.

        The local-contrast window inevitably pulls the mask ~window/2 px inside
        the real edge, so the raw outline is a shrunken copy of the shape.  Here
        we take the seed's own colour and re-grow it: every nearby pixel within
        a colour tolerance of the seed's median colour joins the shape.  The
        tolerance is derived from the seed's own colour spread, so a flat shape
        gets a tight tolerance and a gradient-filled one gets a loose one.

        Returns the refined contour, or None if refinement did not pan out.
        """
        H, W = frame.shape[:2]
        x, y, w, h = cv2.boundingRect(seed)
        pad = 2 * self.window
        x0, y0 = max(x - pad, 0), max(y - pad, 0)
        x1, y1 = min(x + w + pad, W), min(y + h + pad, H)

        roi = frame[y0:y1, x0:x1]
        roi_seed = seed[y0:y1, x0:x1]

        # CIE-Lab so that "colour distance" is roughly perceptual, and so that
        # brightness shading counts for less than an actual change of hue.
        lab = cv2.cvtColor(cv2.medianBlur(roi, 5), cv2.COLOR_BGR2LAB).astype(np.float32)
        seed_px = lab[roi_seed > 0]
        if len(seed_px) < 10:
            return None

        med = np.median(seed_px, axis=0)
        dist = np.linalg.norm(lab - med, axis=2)
        # 90th-percentile spread inside the seed -> how much variation this
        # particular shape already contains (flat fill vs. gradient fill).
        spread = float(np.percentile(np.linalg.norm(seed_px - med, axis=1), 90))
        tol = max(12.0, 2.5 * spread)

        grown = ((dist <= tol).astype(np.uint8)) * 255
        grown = cv2.morphologyEx(
            grown, cv2.MORPH_CLOSE,
            cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (7, 7)))

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
        # Shift back from ROI coordinates into full-frame coordinates.
        best[:, :, 0] += x0
        best[:, :, 1] += y0
        return best

    # ------------------------------------------------------------- detect
    def detect(self, frame: np.ndarray) -> list:
        h, w = frame.shape[:2]
        frame_area = float(h * w)
        mask = self.texture_mask(frame)

        # RETR_EXTERNAL: we want whole shapes, not holes inside them.
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        shapes = []
        for c in contours:
            area = cv2.contourArea(c)
            if not (self.min_area_frac * frame_area <= area <= self.max_area_frac * frame_area):
                continue

            # Snap the (inset) texture blob out to the real colour edge.
            seed = np.zeros((h, w), np.uint8)
            cv2.drawContours(seed, [c], -1, 255, -1)
            refined = self._refine(frame, seed)
            if refined is not None:
                r_area = cv2.contourArea(refined)
                # Sanity-check: refinement should grow the blob a little, not
                # bleed across the whole frame.
                if area <= r_area <= 4.0 * area and r_area <= self.max_area_frac * frame_area:
                    c, area = refined, r_area

            # Solid convex-ish blobs only; this rejects ragged texture patches.
            hull_area = cv2.contourArea(cv2.convexHull(c))
            if hull_area <= 0 or area / hull_area < self.min_solidity:
                continue

            # Smooth the jagged pixel staircase into clean polygon edges.
            peri = cv2.arcLength(c, True)
            c = cv2.approxPolyDP(c, self.smooth_eps_frac * peri, True)

            m = cv2.moments(c)
            if m["m00"] == 0:
                continue
            cx = int(round(m["m10"] / m["m00"]))
            cy = int(round(m["m01"] / m["m00"]))
            shapes.append(Shape(contour=c, center=(cx, cy), area=area))

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
