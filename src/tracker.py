"""Multi-object tracking, so detections persist through occlusion.

Per-frame detection alone has three visible failures when shapes overlap, all of
which a viewer notices immediately:

  1. a shape vanishes for a few frames, because the merged blob fails the
     solidity gate;
  2. its centre jumps, because the centroid of a half-hidden shape is genuinely
     not the centroid of the shape;
  3. its label flickers -- a partly covered trapezoid really does have six
     visible corners.

All three come from the same root cause: a single frame does not contain enough
information to describe an occluded object.  Earlier frames do.  So this module
keeps state across frames.

  * Tracks are matched to detections by predicted position, nearest first.
  * An unmatched track is not dropped immediately.  It coasts on a constant
    velocity estimate for a few frames, still reporting its last known outline,
    which covers brief occlusions.
  * A detection whose area has collapsed relative to the track's established
    size is treated as partially occluded: the outline and centre come from the
    motion model rather than from the truncated blob.
  * Labels are a majority vote over recent unoccluded frames, so one bad frame
    cannot rename a shape.
"""

import collections
import itertools

import cv2
import numpy as np


class Track:
    """One object followed across frames."""

    _ids = itertools.count(1)

    def __init__(self, shape, label_window: int):
        self.id = next(Track._ids)
        self.center = np.array(shape.center, dtype=np.float64)
        self.velocity = np.zeros(2)
        self.contour = shape.contour.copy()
        self.area = shape.area
        self.areas = collections.deque([shape.area], maxlen=label_window)
        self.labels = collections.deque([shape.name()], maxlen=label_window)
        self.hits = 1
        self.missed = 0
        self.occluded = False     # matched, but only partly visible
        self.coasting = False     # not matched at all this frame
        self.last_clipped = bool(shape.clipped)  # was touching the border

    # ---------------------------------------------------------- properties
    @property
    def reference_area(self) -> float:
        """Established size, robust to frames where the shape was truncated."""
        return float(np.median(self.areas))

    @property
    def label(self) -> str:
        """Majority vote, so one odd frame cannot rename the shape."""
        return collections.Counter(self.labels).most_common(1)[0][0]

    def predict(self) -> np.ndarray:
        return self.center + self.velocity

    # -------------------------------------------------------------- update
    def update(self, shape, occlusion_ratio: float, smooth: float):
        """Fold in a matched detection."""
        ref = self.reference_area
        truncated = shape.area < occlusion_ratio * ref

        if truncated:
            # The blob is a fragment; its centroid is not the shape's centroid.
            # Coast instead, and keep the outline we already trust.
            self.occluded = True
            self._coast()
            # Still record the area so a shape that shrinks for real (moving
            # away from the camera) eventually re-establishes its size.
            self.areas.append(shape.area)
        else:
            self.occluded = False
            new_c = np.array(shape.center, dtype=np.float64)
            v = new_c - self.center
            # Exponential smoothing: responsive to real motion, unmoved by the
            # pixel-level jitter of a re-traced contour.
            self.velocity = smooth * self.velocity + (1.0 - smooth) * v
            self.center = new_c
            self.contour = shape.contour.copy()
            self.area = shape.area
            self.areas.append(shape.area)
            self.labels.append(shape.name())
        self.last_clipped = bool(shape.clipped)

        self.coasting = False
        self.hits += 1
        self.missed = 0

    def mark_missing(self):
        self.missed += 1
        self.coasting = True
        self._coast()

    def _coast(self):
        """Advance on the motion model and carry the outline along."""
        step = self.velocity
        self.center = self.center + step
        if np.abs(step).max() >= 0.5:
            shift = np.round(step).astype(np.int32)
            self.contour = self.contour + shift.reshape(1, 1, 2)


class ShapeTracker:
    """Greedy nearest-neighbour tracker over the detector's output."""

    def __init__(
        self,
        max_missed: int = 12,          # frames a track may coast unseen
        min_hits: int = 3,             # frames before a track is reported
        occlusion_ratio: float = 0.75,  # area below this fraction => truncated
        label_window: int = 15,
        smooth: float = 0.6,
        dedupe_iou: float = 0.6,       # footprints this alike are one object
    ):
        self.max_missed = max_missed
        self.min_hits = min_hits
        self.occlusion_ratio = occlusion_ratio
        self.label_window = label_window
        self.smooth = smooth
        self.dedupe_iou = dedupe_iou
        self.tracks = []

    @staticmethod
    def _gate(track) -> float:
        """How far a match may sit from the prediction.

        Scaled by the object's size, because a big shape can travel further
        between frames before the association becomes implausible, and widened
        while a track is coasting, because an unobserved object's position gets
        less certain the longer it goes unseen.

        That widening is what stops duplicates: a shape emerging from behind
        another reappears some distance from where the motion model guessed, and
        with a fixed gate it would fail to match, spawn a second track, and the
        scene would briefly contain six shapes instead of five.
        """
        base = 40.0 + 0.6 * float(np.sqrt(max(track.reference_area, 1.0)))
        return base * (1.0 + 0.5 * track.missed)

    def update(self, shapes: list, frame_shape=None) -> list:
        # --- associate: cheapest plausible pair first -------------------
        pairs = []
        for ti, t in enumerate(self.tracks):
            p = t.predict()
            for si, s in enumerate(shapes):
                d = float(np.linalg.norm(p - np.array(s.center, dtype=np.float64)))
                if d <= self._gate(t):
                    pairs.append((d, ti, si))
        pairs.sort()

        used_t, used_s = set(), set()
        for _, ti, si in pairs:
            if ti in used_t or si in used_s:
                continue
            self.tracks[ti].update(shapes[si], self.occlusion_ratio, self.smooth)
            used_t.add(ti)
            used_s.add(si)

        for ti, t in enumerate(self.tracks):
            if ti not in used_t:
                t.mark_missing()

        for si, s in enumerate(shapes):
            if si not in used_s:
                self.tracks.append(Track(s, self.label_window))

        self._retire(frame_shape)
        return [t for t in self.tracks
                if t.hits >= self.min_hits and t.missed <= self.max_missed]

    def _retire(self, frame_shape):
        """Drop tracks that have earned no further benefit of the doubt.

        Two tempting extra rules were tried here and both were measured and
        removed, which is worth recording so they do not get re-invented:

          * *Suppress a coasting track overlapping a visible one.*  Sounds like
            duplicate removal, but a shape hidden **behind** another is exactly
            a coasting track overlapping a visible one, so it deletes precisely
            the tracks worth keeping.  All-five-shapes fell to 56%, below the
            untracked baseline of 60%.
          * *Retire tracks last seen touching the border,* on the theory that a
            shape at the edge is leaving rather than hiding.  Sweeping the leash
            from 2 to 12 frames left the phantom rate pinned at 2.7% while
            all-five climbed steadily, so the rule cost accuracy and bought
            nothing.

        Duplicates are handled at association time instead, by widening the gate
        while a track coasts.
        """
        alive = [t for t in self.tracks if t.missed <= self.max_missed]

        if frame_shape is not None:
            h, w = frame_shape[:2]
            kept = []
            for t in alive:
                if t.coasting:
                    x, y = t.center
                    # Predicted straight off the edge => it left the scene.
                    if not (-20 <= x <= w + 20 and -20 <= y <= h + 20):
                        continue
                kept.append(t)
            alive = kept

        self.tracks = self._dedupe(alive)

    @staticmethod
    def _bbox_iou(a, b) -> float:
        ax, ay, aw, ah = cv2.boundingRect(a)
        bx, by, bw, bh = cv2.boundingRect(b)
        x1, y1 = max(ax, bx), max(ay, by)
        x2, y2 = min(ax + aw, bx + bw), min(ay + ah, by + bh)
        if x2 <= x1 or y2 <= y1:
            return 0.0
        inter = (x2 - x1) * (y2 - y1)
        return inter / float(aw * ah + bw * bh - inter)

    def _dedupe(self, tracks: list) -> list:
        """Collapse two tracks that are plainly following the same object.

        This is the *strict* version of the overlap rule rejected above.  Merely
        overlapping is not evidence of duplication -- an occluded shape overlaps
        its occluder -- but near-identical footprints are, because two different
        shapes do not occupy the same box.  Sweeping the threshold: 0.5 was
        still deleting real tracks (all-five 66.8%), 0.8 caught almost nothing,
        and 0.6 cut phantoms from 2.7% to 2.0% for 0.3% of all-five.

        Worth the trade for a landing system: reporting a marker that is not
        there is worse than briefly missing one that is.
        """
        drop = set()
        for i in range(len(tracks)):
            for j in range(i + 1, len(tracks)):
                a, b = tracks[i], tracks[j]
                if self._bbox_iou(a.contour, b.contour) > self.dedupe_iou:
                    # Keep whichever has more evidence behind it.
                    loser = b if (a.hits, not a.coasting) >= (b.hits, not b.coasting) else a
                    drop.add(id(loser))
        return [t for t in tracks if id(t) not in drop]
