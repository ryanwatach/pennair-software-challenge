"""Pinhole camera model: turns pixel centers into 3D points.

Conventions are OpenCV's: +X right, +Y **down**, +Z forward along the optical
axis, origin at the camera's optical center.  Distances come out in whatever
unit the reference object is given in -- inches here, since the challenge
specifies a circle of radius 10 in.
"""

import math
from dataclasses import dataclass

# The intrinsic matrix supplied with the challenge.
#   K = [[2564.3186869, 0, 0], [0, 2569.70273111, 0], [0, 0, 1]]
K_FX = 2564.3186869
K_FY = 2569.70273111
K_CX = 0.0
K_CY = 0.0

# Focal lengths are in pixels, so they are tied to the resolution they were
# calibrated at.  These values imply a 41.0 x 23.7 degree field of view at
# 1920x1080, which is an ordinary camera; read against the 960x540 static image
# they would imply 21.2 x 12.0 degrees, an unlikely telephoto.  So K belongs to
# the video resolution, and has to be rescaled for any other frame size.
K_REF_WIDTH = 1920


@dataclass
class Camera:
    fx: float
    fy: float
    cx: float
    cy: float

    @classmethod
    def for_frame(cls, width: int, height: int, literal_principal_point: bool = False):
        """Build the challenge camera, rescaled to this frame size.

        On the principal point: the supplied K has cx = cy = 0, which would put
        the optical axis at the top-left *corner* of the sensor.  No real camera
        is built that way -- the principal point lands near the image center, and
        a calibration returning (0,0) for a 1920x1080 frame would be rejected as
        broken.  It reads as a placeholder left in the matrix rather than a
        measured value, so by default we substitute the image center, which is
        the standard assumption for an uncalibrated principal point.

        This choice only shifts the origin of X and Y; it does not affect depth
        at all.  Pass literal_principal_point=True to use K exactly as written,
        in which case X and Y are measured from the ray through pixel (0,0)
        instead of from the optical axis.
        """
        s = width / float(K_REF_WIDTH)
        if literal_principal_point:
            cx, cy = K_CX * s, K_CY * s
        else:
            cx, cy = width / 2.0, height / 2.0
        return cls(fx=K_FX * s, fy=K_FY * s, cx=cx, cy=cy)

    # ------------------------------------------------------------ depth
    def depth_from_circle_area(self, area_px: float, real_radius: float) -> float:
        """Depth of a circle of known radius, from the pixel area it covers.

        A circle of radius R at depth Z projects to an ellipse of semi-axes
        (fx*R/Z, fy*R/Z), so its pixel area is pi*fx*fy*R^2 / Z^2.  Solving:

            Z = R * sqrt(pi * fx * fy / area_px)

        Area is used rather than a measured radius because it integrates over
        every pixel of the blob, so a few ragged boundary pixels barely move the
        estimate -- whereas a single radius measurement is at their mercy.
        """
        if area_px <= 0:
            raise ValueError("area must be positive")
        return real_radius * math.sqrt(math.pi * self.fx * self.fy / area_px)

    # ------------------------------------------------------ backproject
    def backproject(self, u: float, v: float, depth: float) -> tuple:
        """Pixel (u,v) at known depth -> (X, Y, Z) in the camera frame."""
        x = (u - self.cx) * depth / self.fx
        y = (v - self.cy) * depth / self.fy
        return x, y, depth

    def __str__(self):
        return (f"fx={self.fx:.2f} fy={self.fy:.2f} "
                f"cx={self.cx:.1f} cy={self.cy:.1f}")
