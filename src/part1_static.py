"""Part 1: detect, outline and locate shapes in the static image."""

import argparse
import os
import sys

import cv2

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from detector import ShapeDetector, annotate  # noqa: E402


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--image", default="assets/PennAir 2024 App Static.png")
    p.add_argument("--out", default="output/part1_static_annotated.png")
    p.add_argument("--mask-out", default="output/part1_mask.png")
    p.add_argument("--show", action="store_true", help="open a preview window")
    args = p.parse_args()

    frame = cv2.imread(args.image)
    if frame is None:
        sys.exit(f"Could not read image: {args.image}")

    det = ShapeDetector()
    shapes = det.detect(frame)

    print(f"Detected {len(shapes)} shapes in {args.image} ({frame.shape[1]}x{frame.shape[0]})")
    for i, s in enumerate(shapes, 1):
        print(f"  {i}. {s.name():<14} center=({s.center[0]:4d}, {s.center[1]:4d})  area={s.area:9.1f} px^2")

    os.makedirs(os.path.dirname(args.out) or ".", exist_ok=True)
    cv2.imwrite(args.out, annotate(frame, shapes))
    cv2.imwrite(args.mask_out, det.texture_mask(frame))
    print(f"\nWrote {args.out}\nWrote {args.mask_out}")

    if args.show:
        cv2.imshow("Part 1 - detected shapes", annotate(frame, shapes))
        cv2.waitKey(0)
        cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
