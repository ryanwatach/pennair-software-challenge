"""Part 2: run the Part 1 detector over a video, one frame at a time.

The challenge asks for the video to be treated as a *stream*: the aircraft
does not get to see the whole flight in advance, so nothing here may look
ahead, buffer the clip, or make a second pass.  The loop below reads exactly
one frame, detects on it, writes it, and forgets it -- no frame ever needs to
coexist with another in memory.
"""

import argparse
import os
import sys
import time

import cv2

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from detector import ShapeDetector, annotate  # noqa: E402


def open_writer(path, fps, size):
    """Open an H.264 writer if the build supports it, else fall back to mp4v.

    H.264 ('avc1') matters because GitHub will only play H.264 in a README;
    mp4v files download instead of playing inline.
    """
    for tag in ("avc1", "mp4v"):
        w = cv2.VideoWriter(path, cv2.VideoWriter_fourcc(*tag), fps, size)
        if w.isOpened():
            return w, tag
        w.release()
    raise RuntimeError("no usable video codec found")


def hud(frame, text_lines):
    """Draw a small translucent status panel in the top-left corner."""
    pad, lh = 10, 26
    h = pad * 2 + lh * len(text_lines)
    panel = frame[0:h, 0:360].copy()
    frame[0:h, 0:360] = cv2.addWeighted(
        panel, 0.45, panel * 0 + 20, 0.55, 0)
    for i, t in enumerate(text_lines):
        cv2.putText(frame, t, (pad, pad + lh * (i + 1) - 7),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 1, cv2.LINE_AA)
    return frame


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--video", default="assets/PennAir 2024 App Dynamic.mp4")
    p.add_argument("--out", default="output/part2_dynamic_annotated.mp4")
    p.add_argument("--show", action="store_true", help="live preview window")
    p.add_argument("--max-frames", type=int, default=0, help="0 = whole video")
    p.add_argument("--out-width", type=int, default=1280,
                   help="downscale the OUTPUT file only; detection stays full-res")
    args = p.parse_args()

    cap = cv2.VideoCapture(args.video)
    if not cap.isOpened():
        sys.exit(f"Could not open video: {args.video}")

    fps = cap.get(cv2.CAP_PROP_FPS) or 30.0
    W = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    H = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    total = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))

    out_scale = min(1.0, args.out_width / float(W))
    out_size = (int(W * out_scale), int(H * out_scale))

    os.makedirs(os.path.dirname(args.out) or ".", exist_ok=True)
    writer, codec = open_writer(args.out, fps, out_size)

    print(f"in : {args.video}  {W}x{H} @ {fps:.2f} fps, {total} frames")
    print(f"out: {args.out}  {out_size[0]}x{out_size[1]} codec={codec}")

    det = ShapeDetector()
    n, detect_time, t_start = 0, 0.0, time.perf_counter()

    while True:
        ok, frame = cap.read()      # <-- the only place a frame enters memory
        if not ok:
            break

        t0 = time.perf_counter()
        shapes = det.detect(frame)
        dt = time.perf_counter() - t0
        detect_time += dt
        n += 1

        vis = annotate(frame, shapes)
        if out_scale < 1.0:
            vis = cv2.resize(vis, out_size, interpolation=cv2.INTER_AREA)
        hud(vis, [f"frame {n}/{total}",
                  f"shapes: {len(shapes)}",
                  f"detect: {dt*1000:.0f} ms ({1.0/max(dt,1e-6):.0f} fps)"])
        writer.write(vis)

        if args.show:
            cv2.imshow("Part 2 - streaming detection", vis)
            if cv2.waitKey(1) & 0xFF == ord("q"):
                break
        if n % 200 == 0:
            print(f"  {n}/{total} frames, {n/detect_time:.1f} fps avg")
        if args.max_frames and n >= args.max_frames:
            break

    cap.release()
    writer.release()
    if args.show:
        cv2.destroyAllWindows()

    wall = time.perf_counter() - t_start
    print(f"\nprocessed {n} frames")
    print(f"detection only : {n/detect_time:6.1f} fps avg  ({detect_time/n*1000:.1f} ms/frame)")
    print(f"end-to-end     : {n/wall:6.1f} fps  (includes decode, draw, encode)")
    print(f"source rate    : {fps:6.1f} fps  ->  "
          f"{'REAL-TIME OK' if n/detect_time >= fps else 'TOO SLOW'}")
    print(f"wrote {args.out}")


if __name__ == "__main__":
    main()
