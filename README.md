# PennAiR Software Challenge — Shape Detection

Detects solid shapes on a textured background, traces their outlines, and marks
their centers.

## Approach

The detector never looks for a specific colour. It keys on **texture**: the
targets are flat-shaded solids, while natural backgrounds (grass, gravel,
carpet) are visually busy.

1. **Local-contrast map** — median-blur the frame, then compute a sliding-window
   standard deviation per colour channel using box filters (O(1) per pixel
   regardless of window size). Take the max across channels: a pixel is "busy"
   if *any* channel is busy.
2. **Adaptive threshold** — mark a pixel smooth if its busyness falls below
   `0.35 x median(busyness)`. Using the frame's own median makes the cut adapt
   to whatever the background happens to be. *(Otsu fails here: the background
   dominates the histogram, so Otsu bisects the background rather than
   separating it from the shapes.)*
3. **Morphological cleanup** — open to drop stray smooth pixels, close to seal
   shape interiors.
4. **Colour refinement** — the contrast window pulls the mask ~`window/2` px
   inside the true edge, so each blob is re-grown in CIE-Lab space out to its
   real colour boundary. The tolerance comes from the seed's own colour spread,
   so a flat fill gets a tight tolerance and a gradient fill a loose one.
5. **Filter & measure** — keep components that pass area and solidity checks,
   smooth the contour, and take the center from image moments.

## Setup

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

## Part 1 — Static image

```bash
python src/part1_static.py
```

Reads `assets/PennAir 2024 App Static.png`, writes
`output/part1_static_annotated.png` (outlines + centers) and
`output/part1_mask.png` (the intermediate smooth-region mask).

Result — all 5 shapes found, each classified from its vertex count:

| Shape         | Center      | Area (px²) |
|---------------|-------------|------------|
| pentagon      | (691, 344)  | 8771       |
| triangle      | (279, 320)  | 5583       |
| quadrilateral | (839, 148)  | 5562       |
| circle        | (553, 104)  | 5092       |
| quadrilateral | (112, 76)   | 3562       |

## Layout

```
assets/   input image / video
src/      detector.py (core algorithm), part1_static.py
output/   generated annotations
```
