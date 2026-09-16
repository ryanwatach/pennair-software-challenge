"""Part 6: track shapes across frames so they survive occlusion.

Per-frame detection is memoryless, and it shows whenever shapes overlap: a shape
drops out for a few frames, its centre jumps to the centroid of the visible
sliver, and its label flickers.  Adding a tracker gives every shape a persistent
identity and lets earlier frames stand in for the information a single occluded
frame does not contain.

Run with --compare to render the untracked and tracked results side by side.
"""

import argparse
import collections
import os
import statistics
import sys
import time

import cv2
import numpy as np

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from camera import Camera            # noqa: E402
from detector import ShapeDetector   # noqa: E402
from part4_3d import find_reference_circle  # noqa: E402
from tracker import ShapeTracker     # noqa: E402

CIRCLE_RADIUS_IN = 10.0

# Distinct colours per track id, so identity is visible at a glance.
PALETTE = [(60, 220, 255), (80, 220, 80), (255, 140, 60), (200, 120, 255),
           (60, 160, 255), (255, 210, 90), (140, 255, 200), (255, 90, 160)]


def draw_tracks(frame, tracks, cam=None, depth=None):
    out = frame.copy()
    for t in tracks:
        col = PALETTE[t.id % len(PALETTE)]
        # Dashed-looking thin outline while coasting, solid when actually seen.
        thickness = 2 if (t.coasting or t.occluded) else 3
        cv2.drawContours(out, [t.contour], -1, col, thickness)
        cx, cy = int(round(t.center[0])), int(round(t.center[1]))
        cv2.drawMarker(out, (cx, cy), (255, 255, 255), cv2.MARKER_CROSS, 18, 2)
        cv2.circle(out, (cx, cy), 5, col, -1)

        state = ""
        if t.coasting:
            state = "  OCCLUDED (predicted)"
        elif t.occluded:
            state = "  PARTIAL (predicted)"
        lines = [f"#{t.id} {t.label}{state}"]
        if cam is not None and depth is not None:
            X, Y, Z = cam.backproject(cx, cy, depth)
            lines.append(f"X {X:+6.1f}  Y {Y:+6.1f}  Z {Z:6.1f} in")

        font, sc, th = cv2.FONT_HERSHEY_SIMPLEX, 0.5, 1
        w = max(cv2.getTextSize(l, font, sc, th)[0][0] for l in lines)
        tx = min(max(cx + 14, 2), out.shape[1] - w - 2)
        ty = max(cy - 14 - 18 * (len(lines) - 1), 16)
        for i, l in enumerate(lines):
            cv2.putText(out, l, (tx, ty + 18 * i), font, sc, (0, 0, 0), 4, cv2.LINE_AA)
            cv2.putText(out, l, (tx, ty + 18 * i), font, sc, (255, 255, 255), th, cv2.LINE_AA)
    return out


def banner(img, text, colour=(255, 255, 255)):
    cv2.putText(img, text, (12, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 0, 0), 5, cv2.LINE_AA)
    cv2.putText(img, text, (12, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.8, colour, 2, cv2.LINE_AA)
    return img


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--video", default="assets/PennAir 2024 App Dynamic.mp4")
    p.add_argument("--out", default="output/part6_tracked.mp4")
    p.add_argument("--compare", action="store_true",
                   help="stack untracked (top) against tracked (bottom)")
    p.add_argument("--max-frames", type=int, default=0)
    p.add_argument("--out-width", type=int, default=1280)
    args = p.parse_args()

    cap = cv2.VideoCapture(args.video)
    if not cap.isOpened():
        sys.exit(f"Could not open {args.video}")
    fps = cap.get(cv2.CAP_PROP_FPS) or 30.0
    W = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    H = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    total = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
    cam = Camera.for_frame(W, H)

    sc = min(1.0, args.out_width / float(W))
    panel = (int(W * sc), int(H * sc))
    size = (panel[0], panel[1] * 2) if args.compare else panel
    os.makedirs(os.path.dirname(args.out) or ".", exist_ok=True)
    writer = cv2.VideoWriter(args.out, cv2.VideoWriter_fourcc(*"avc1"), fps, size)
    if not writer.isOpened():
        writer = cv2.VideoWriter(args.out, cv2.VideoWriter_fourcc(*"mp4v"), fps, size)

    det, trk = ShapeDetector(), ShapeTracker()
    depths = collections.deque(maxlen=31)
    raw_hist, trk_hist = collections.Counter(), collections.Counter()
    flips, prev_label = 0, {}
    n, t0 = 0, time.perf_counter()

    while True:
        ok, frame = cap.read()
        if not ok:
            break
        shapes = det.detect(frame)
        ref = find_reference_circle(shapes)
        if ref is not None:
            depths.append(cam.depth_from_circle_area(ref.area, CIRCLE_RADIUS_IN))
        depth = statistics.median(depths) if depths else None

        tracks = trk.update(shapes, frame.shape)
        raw_hist[len(shapes)] += 1
        trk_hist[len(tracks)] += 1
        for t in tracks:
            if t.id in prev_label and prev_label[t.id] != t.label:
                flips += 1
            prev_label[t.id] = t.label

        vis = draw_tracks(frame, tracks, cam, depth)
        vis = cv2.resize(vis, panel, interpolation=cv2.INTER_AREA)
        occ = sum(1 for t in tracks if t.coasting or t.occluded)
        banner(vis, f"TRACKED   {len(tracks)} shapes"
                    f"{f'  ({occ} predicted through occlusion)' if occ else ''}",
               (120, 255, 120))

        if args.compare:
            from detector import annotate
            top = cv2.resize(annotate(frame, shapes), panel, interpolation=cv2.INTER_AREA)
            banner(top, f"PER-FRAME ONLY   {len(shapes)} shapes", (120, 200, 255))
            vis = np.vstack([top, vis])

        writer.write(vis)
        n += 1
        if n % 300 == 0:
            print(f"  {n}/{total}")
        if args.max_frames and n >= args.max_frames:
            break

    cap.release(); writer.release()
    wall = time.perf_counter() - t0

    def pct(h, k):
        return 100.0 * h.get(k, 0) / max(sum(h.values()), 1)

    print(f"\nprocessed {n} frames at {n/wall:.1f} fps end-to-end")
    print(f"  all 5 shapes present:  per-frame {pct(raw_hist,5):5.1f}%"
          f"   ->  tracked {pct(trk_hist,5):5.1f}%")
    over_r = sum(v for k, v in raw_hist.items() if k > 5)
    over_t = sum(v for k, v in trk_hist.items() if k > 5)
    print(f"  more than 5 reported:  per-frame {100*over_r/n:5.1f}%"
          f"   ->  tracked {100*over_t/n:5.1f}%   (cost of coasting)")
    print(f"  label changes per run: {flips} after majority vote")
    print(f"wrote {args.out}")


if __name__ == "__main__":
    main()
