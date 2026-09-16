"""Build small looping GIF previews for the README.

GitHub will not play a committed .mp4 inline, but it renders GIFs, so each
result gets a short preview next to a link to the full-resolution video.
"""

import argparse
import os
import sys

import cv2
from PIL import Image


def make_gif(video, out, start=0.0, seconds=6.0, width=560, fps=10):
    cap = cv2.VideoCapture(video)
    if not cap.isOpened():
        sys.exit(f"could not open {video}")
    src_fps = cap.get(cv2.CAP_PROP_FPS) or 30.0
    cap.set(cv2.CAP_PROP_POS_FRAMES, int(start * src_fps))
    step = max(1, int(round(src_fps / fps)))
    want = int(seconds * fps)

    frames, i = [], 0
    while len(frames) < want:
        ok, f = cap.read()
        if not ok:
            break
        if i % step == 0:
            h, w = f.shape[:2]
            g = cv2.resize(f, (width, int(h * width / w)), interpolation=cv2.INTER_AREA)
            frames.append(Image.fromarray(cv2.cvtColor(g, cv2.COLOR_BGR2RGB)))
        i += 1
    cap.release()
    if not frames:
        sys.exit(f"no frames read from {video}")

    os.makedirs(os.path.dirname(out) or ".", exist_ok=True)
    # Palette-quantise so the file stays small enough to sit in a README.
    frames = [f.convert("P", palette=Image.ADAPTIVE, colors=64) for f in frames]
    frames[0].save(out, save_all=True, append_images=frames[1:],
                   duration=int(1000 / fps), loop=0, optimize=True)
    mb = os.path.getsize(out) / 1e6
    print(f"  {out}  {len(frames)} frames  {mb:.1f} MB")


if __name__ == "__main__":
    p = argparse.ArgumentParser()
    p.add_argument("--video"); p.add_argument("--out")
    p.add_argument("--start", type=float, default=0.0)
    p.add_argument("--seconds", type=float, default=6.0)
    p.add_argument("--width", type=int, default=560)
    p.add_argument("--fps", type=int, default=10)
    a = p.parse_args()
    make_gif(a.video, a.out, a.start, a.seconds, a.width, a.fps)
