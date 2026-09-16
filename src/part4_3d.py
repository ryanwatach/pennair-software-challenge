"""Part 4: report each shape's center as (X, Y, Z) in the camera frame.

Scale comes from the one object whose real size we are told: the circle, radius
10 in.  Measuring how large it appears fixes the depth, and the challenge's
flat-surface assumption then extends that depth to every other shape -- all the
shapes lie on one plane, so they share a Z.

Because that plane is flat and the camera height is steady, Z should barely move
between frames.  The circle is therefore treated as a calibration source rather
than a per-frame measurement: its estimate feeds a running median, which is what
gets used.  That keeps the numbers stable, and keeps them available on frames
where the circle has drifted out of shot entirely.
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
from camera import Camera          # noqa: E402
from detector import ShapeDetector  # noqa: E402

CIRCLE_RADIUS_IN = 10.0


def find_reference_circle(shapes):
    """The most circle-like fully-visible shape, or None.

    A clipped circle is rejected: only part of its area is in frame, which would
    read as a smaller circle and therefore a falsely large depth.
    """
    best, best_c = None, 0.0
    for s in shapes:
        if s.clipped:
            continue
        c = s.circularity
        if c > 0.90 and c > best_c:
            best, best_c = s, c
    return best


def annotate_3d(frame, shapes, cam, depth, ref):
    """Outline each shape and label it with its 3D center."""
    out = frame.copy()
    for s in shapes:
        is_ref = ref is not None and s is ref
        colour = (0, 200, 255) if is_ref else (0, 0, 255)
        cv2.drawContours(out, [s.contour], -1, colour, 3)
        cx, cy = s.center
        cv2.drawMarker(out, (cx, cy), (255, 255, 255), cv2.MARKER_CROSS, 18, 3)
        cv2.circle(out, (cx, cy), 5, colour, -1)

        if depth is None:
            lines = [s.name(), "depth unknown"]
        else:
            X, Y, Z = cam.backproject(cx, cy, depth)
            lines = [f"{s.name()}{'  [scale ref]' if is_ref else ''}",
                     f"X {X:+7.1f} in   Y {Y:+7.1f} in",
                     f"Z {Z:7.1f} in  ({Z/12:.1f} ft)"]

        font, sc, th = cv2.FONT_HERSHEY_SIMPLEX, 0.5, 1
        w = max(cv2.getTextSize(t, font, sc, th)[0][0] for t in lines)
        tx = min(max(cx + 14, 2), out.shape[1] - w - 2)
        ty = max(cy - 14 - 18 * (len(lines) - 1), 16)
        for i, t in enumerate(lines):
            p = (tx, ty + 18 * i)
            cv2.putText(out, t, p, font, sc, (0, 0, 0), 4, cv2.LINE_AA)
            cv2.putText(out, t, p, font, sc, (255, 255, 255), th, cv2.LINE_AA)
    return out


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--video", default="assets/PennAir 2024 App Dynamic.mp4")
    p.add_argument("--image", default=None, help="run on a single image instead")
    p.add_argument("--out", default="output/part4_3d_annotated.mp4")
    p.add_argument("--max-frames", type=int, default=0)
    p.add_argument("--out-width", type=int, default=1280)
    p.add_argument("--literal-principal-point", action="store_true",
                   help="use K's cx=cy=0 verbatim instead of the image center")
    args = p.parse_args()

    det = ShapeDetector()

    # ------------------------------------------------------------ image
    if args.image:
        frame = cv2.imread(args.image)
        if frame is None:
            sys.exit(f"Could not read {args.image}")
        H, W = frame.shape[:2]
        cam = Camera.for_frame(W, H, args.literal_principal_point)
        shapes = det.detect(frame)
        ref = find_reference_circle(shapes)
        if ref is None:
            sys.exit("No circle found -- nothing to take scale from.")
        depth = cam.depth_from_circle_area(ref.area, CIRCLE_RADIUS_IN)
        print(f"camera: {cam}")
        print(f"scale reference: circle, {ref.area:.0f} px^2 -> depth "
              f"{depth:.1f} in ({depth/12:.2f} ft)\n")
        for s in shapes:
            X, Y, Z = cam.backproject(*s.center, depth)
            print(f"  {s.name():<16} px{str(s.center):>14}   "
                  f"X{X:+8.1f}  Y{Y:+8.1f}  Z{Z:8.1f}  (inches)")
        outp = args.out.replace(".mp4", ".png")
        os.makedirs(os.path.dirname(outp) or ".", exist_ok=True)
        cv2.imwrite(outp, annotate_3d(frame, shapes, cam, depth, ref))
        print(f"\nwrote {outp}")
        return

    # ------------------------------------------------------------ video
    cap = cv2.VideoCapture(args.video)
    if not cap.isOpened():
        sys.exit(f"Could not open {args.video}")
    fps = cap.get(cv2.CAP_PROP_FPS) or 30.0
    W = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    H = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    total = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
    cam = Camera.for_frame(W, H, args.literal_principal_point)
    print(f"camera: {cam}")

    scale = min(1.0, args.out_width / float(W))
    size = (int(W * scale), int(H * scale))
    os.makedirs(os.path.dirname(args.out) or ".", exist_ok=True)
    writer = cv2.VideoWriter(args.out, cv2.VideoWriter_fourcc(*"avc1"), fps, size)
    if not writer.isOpened():
        writer = cv2.VideoWriter(args.out, cv2.VideoWriter_fourcc(*"mp4v"), fps, size)

    recent = collections.deque(maxlen=31)   # running window of circle depths
    per_frame, n, t0 = [], 0, time.perf_counter()

    while True:
        ok, frame = cap.read()
        if not ok:
            break
        shapes = det.detect(frame)
        ref = find_reference_circle(shapes)
        if ref is not None:
            z = cam.depth_from_circle_area(ref.area, CIRCLE_RADIUS_IN)
            recent.append(z)
            per_frame.append(z)
        depth = statistics.median(recent) if recent else None

        vis = annotate_3d(frame, shapes, cam, depth, ref)
        if scale < 1.0:
            vis = cv2.resize(vis, size, interpolation=cv2.INTER_AREA)
        txt = (f"depth {depth:.1f} in ({depth/12:.1f} ft)" if depth else "depth unknown")
        for col, th in [((0, 0, 0), 4), ((255, 255, 255), 1)]:
            cv2.putText(vis, f"frame {n+1}/{total}   shapes {len(shapes)}   {txt}",
                        (10, 26), cv2.FONT_HERSHEY_SIMPLEX, 0.6, col, th, cv2.LINE_AA)
        writer.write(vis)
        n += 1
        if args.max_frames and n >= args.max_frames:
            break

    cap.release(); writer.release()
    wall = time.perf_counter() - t0

    print(f"\nprocessed {n} frames at {n/wall:.1f} fps end-to-end")
    if per_frame:
        a = np.array(per_frame)
        print(f"circle seen in {len(a)}/{n} frames ({100*len(a)/n:.1f}%)")
        print(f"depth  median {np.median(a):7.1f} in   mean {a.mean():7.1f} in"
              f"   sd {a.std():5.2f} in   range [{a.min():.1f}, {a.max():.1f}]")
        print(f"       -> {np.median(a)/12:.2f} ft, spread {100*a.std()/a.mean():.2f}% of mean")
        print("A flat surface at steady altitude implies a near-constant depth;")
        print("the spread above is the practical check on that assumption.")
    print(f"wrote {args.out}")


if __name__ == "__main__":
    main()
