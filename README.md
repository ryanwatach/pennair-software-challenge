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

## Part 2 — Video (streamed)

```bash
python src/part2_video.py               # whole video -> output/part2_dynamic_annotated.mp4
python src/part2_video.py --show        # live preview window
python src/part2_video.py --max-frames 60   # quick smoke test
```

The video is treated as a **stream**, as the challenge requires: the loop reads
one frame, detects on it, writes it, and forgets it. Nothing looks ahead,
buffers the clip, or makes a second pass.

### Performance

Measured on the full 1837-frame 1920x1080 clip (Apple Silicon, single process):

| Stage | Rate |
|---|---|
| Detection only | **38.7 fps** (25.9 ms/frame) |
| End-to-end (decode + detect + draw + encode) | **33.8 fps** |
| Source video | 30.3 fps |

Comfortably real-time. Three changes got it there from an initial 10-20 fps:

1. **Analyse at reduced resolution.** The mask only has to say *where* shapes
   are; 1080p costs 4x the work for no extra localisation value. The mask is
   built at 960px wide, then each shape is refined at full resolution inside a
   small ROI, so outline precision is not sacrificed.
2. **Box-filter variance.** Local standard deviation via `E[X^2] - E[X]^2` with
   box filters is O(1) per pixel regardless of window size.
3. **Bounded refinement.** Colour growth is confined to a band around the seed,
   which caps the per-shape cost and doubles as a correctness guard.

### Problems solved along the way

- **Touching shapes merged into one blob.** A `CLOSE(15x15, x2)` was welding the
  pentagon to the trapezoid it overlaps. Where two shapes touch, the colour step
  between them is exactly the thin high-texture line separating them, and the
  aggressive close was destroying that signal. Reduced to a single `CLOSE(7x7)`.
- **Colour refinement flooded its ROI.** A green shape on green grass cannot be
  separated by colour at all, so the region grew until it filled the whole ROI.
  Fixed by confining growth to a dilated band around the seed: texture decides
  *where* the shape is, colour only sharpens the edge.
- **Triangles were being reported as pentagons.** A slightly rounded corner makes
  `approxPolyDP` emit two or three vertices a few pixels apart. Fixed by fusing
  vertices closer than 8% of the perimeter, and by widening the refinement band
  so corners are actually recovered rather than clipped.
- **Shapes leaving the frame.** A shape running off the edge is a fragment, not a
  polygon, so naming it from its vertex count is meaningless. These are detected,
  outlined and centred as normal but labelled `shape (clipped)`.

## Part 3 — Background agnostic

```bash
python src/part2_video.py \
    --video "assets/PennAir 2024 App Dynamic Hard.mp4" \
    --out   output/part3_hard_annotated.mp4
```

**Same script, same parameters, no tuning.** The only thing that changes is the
input path. That is the claim of background agnosticism, stated as plainly as it
can be made.

The hard clip swaps grass for asphalt and gives every shape a colour gradient
(magenta->green, blue->yellow, red->yellow). It broke the detector in two
separate places.

### Problem 1: local standard deviation cannot see gradients

Probing pixel values explained the failure immediately:

| Region | local std |
|---|---|
| asphalt background | 11.67 |
| rectangle, magenta end | 11.83 |
| triangle (gradient) | 11.42 |
| trapezoid | 11.50 |
| rectangle, flat green end | 0.00 |

The gradient fills are *exactly as variable* as the asphalt, so only the flat
parts of shapes survived — outlines covered half a circle, half a pentagon, and
the triangle vanished entirely.

Magnitude of variation is the wrong question. The right one is whether a region
varies **smoothly or randomly**, and that is what a second derivative answers: a
linear ramp differentiates to exactly zero, while random grain does not. So the
busyness metric became the local mean of `|Laplacian|`.

Scored against a hand-built ground-truth mask (Youden's J, higher is better):

| Metric | J |
|---|---|
| local std (old) | 0.571 |
| high-pass `\|I-G(σ=1)\|` | 0.986 |
| **local mean of `\|Laplacian\|`** | **0.997** |

*(The ground truth was built by thresholding saturation — useful as a measuring
stick, but deliberately **not** part of the algorithm, since it would defeat the
whole point of being background agnostic.)*

### Problem 2: max-across-channels amplifies chroma noise

The first Laplacian version still lost the magenta half of the rectangle. That
region turned out to be a *constant* colour, `[146,53,159]`, yet still measured
11-13 against a threshold of 10.6 — chroma is subsampled in compressed video, so
a saturated flat fill carries real chroma noise, and taking the **max** across
BGR let that noise speak for the whole pixel.

Averaging the channels instead lets it wash out, while staying sensitive to
shapes that differ from the background in hue but not brightness:

| Channel reduction | recall | false positives |
|---|---|---|
| max | 0.922 | 0.0017 |
| **mean** | **0.997** | 0.0019 |
| grayscale | 0.999 | 0.0021 |

Grayscale scores marginally higher and is cheaper, but it is blind to a shape
that differs from its background only in hue — precisely the case this part is
about — so `mean` is the better trade.

### Problem 3: refinement was destroying detections

Swapping the metric made the grass clip *worse* (all-5 rate 60.3% -> 51.6%). The
green trapezoid on green grass was being found, refined, and then thrown away:
growing a green shape into green grass produced a ragged blob whose solidity
fell to 0.841, just under the 0.85 gate. The refinement made the shape worse and
the filter then killed it.

Fixed with a rule that generalises the earlier anti-shrink guard: **refinement
may only improve a blob.** If it shrinks the region or materially drops its
solidity, keep the seed. Falling back costs a few pixels of inset; accepting a
bad refinement costs the whole detection.

### Results

| Clip | Detection | End-to-end | Frames with all 5 shapes |
|---|---|---|---|
| Grass (Part 2) | 40.8 fps | 35.4 fps | 60.1% |
| Asphalt + gradients (Part 3) | 41.3 fps | 35.8 fps | 59.9% |

Both real-time against a 30.3 fps source. Frames showing fewer than 5 are mostly
correct — shapes genuinely leave the frame as the camera pans.

### Known limitations

- **Low-contrast shapes keep a slightly inset outline.** The white trapezoid on
  grey asphalt has no colour contrast to grow toward, so refinement declines and
  the outline sits a few pixels inside the true edge. Detection and centre are
  unaffected.
- **Occlusion.** When shapes overlap, the visible region is not the shape, so the
  polygon label and the centroid both shift. Addressed in Part 6 with tracking.

## Layout

```
assets/   input image / video
src/      detector.py (core algorithm), part1_static.py, part2_video.py
output/   generated annotations
```
