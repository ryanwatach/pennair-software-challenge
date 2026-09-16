"""Subscribes to camera images, runs the detector, publishes the detections.

The detection code is imported from the repository's src/ rather than copied in,
so the ROS node and the standalone scripts of Parts 1-4 run the *same* algorithm
-- there is no second implementation to drift out of sync.

Topics
------
  sub  image_raw       sensor_msgs/Image
  pub  shapes          pennair_vision_msgs/ShapeArray   (positions + outlines)
  pub  image_annotated sensor_msgs/Image                (for rviz / rqt)
"""

import collections
import statistics

import rclpy
from cv_bridge import CvBridge
from geometry_msgs.msg import Point, Point32, Polygon
from rclpy.node import Node
from sensor_msgs.msg import Image

from pennair_vision_msgs.msg import Shape, ShapeArray

from camera import Camera
from detector import ShapeDetector
from part4_3d import annotate_3d, find_reference_circle

CIRCLE_RADIUS_IN = 10.0


class DetectorNode(Node):
    def __init__(self):
        super().__init__("shape_detector")
        self.declare_parameter("publish_annotated", True)
        self.declare_parameter("estimate_3d", True)
        self.declare_parameter("literal_principal_point", False)

        self.publish_annotated = self.get_parameter("publish_annotated").value
        self.estimate_3d = self.get_parameter("estimate_3d").value

        self.det = ShapeDetector()
        self.bridge = CvBridge()
        self.cam = None                                   # built on first frame
        self.depths = collections.deque(maxlen=31)        # running depth window
        self.n = 0

        # Depth 10 keeps a short queue: if detection falls behind, we would
        # rather drop stale frames than build an ever-growing backlog.
        self.sub = self.create_subscription(Image, "image_raw", self.on_image, 10)
        self.pub_shapes = self.create_publisher(ShapeArray, "shapes", 10)
        self.pub_image = self.create_publisher(Image, "image_annotated", 10)
        self.get_logger().info("shape_detector ready")

    def on_image(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        h, w = frame.shape[:2]
        if self.cam is None:
            self.cam = Camera.for_frame(
                w, h, self.get_parameter("literal_principal_point").value)
            self.get_logger().info(f"camera model: {self.cam}")

        shapes = self.det.detect(frame)

        depth, ref = None, None
        if self.estimate_3d:
            ref = find_reference_circle(shapes)
            if ref is not None:
                self.depths.append(
                    self.cam.depth_from_circle_area(ref.area, CIRCLE_RADIUS_IN))
            if self.depths:
                depth = statistics.median(self.depths)

        out = ShapeArray()
        out.header = msg.header
        out.depth_valid = depth is not None
        out.depth_inches = float(depth) if depth is not None else 0.0

        for s in shapes:
            m = Shape()
            m.label = s.name()
            m.area_px = float(s.area)
            m.clipped = bool(s.clipped)
            m.center_px = Point(x=float(s.center[0]), y=float(s.center[1]), z=0.0)
            m.has_3d = depth is not None
            if depth is not None:
                X, Y, Z = self.cam.backproject(s.center[0], s.center[1], depth)
                m.center_camera = Point(x=float(X), y=float(Y), z=float(Z))
            poly = Polygon()
            poly.points = [Point32(x=float(p[0][0]), y=float(p[0][1]), z=0.0)
                           for p in s.contour]
            m.outline = poly
            out.shapes.append(m)

        self.pub_shapes.publish(out)

        if self.publish_annotated:
            vis = annotate_3d(frame, shapes, self.cam, depth, ref)
            img = self.bridge.cv2_to_imgmsg(vis, encoding="bgr8")
            img.header = msg.header
            self.pub_image.publish(img)

        self.n += 1
        if self.n % 100 == 0:
            d = f"{depth:.1f} in" if depth else "unknown"
            self.get_logger().info(
                f"frame {self.n}: {len(shapes)} shapes, depth {d}")


def main(args=None):
    rclpy.init(args=args)
    node = DetectorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
