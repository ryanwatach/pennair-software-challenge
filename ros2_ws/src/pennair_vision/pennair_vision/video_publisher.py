"""Publishes a video file frame by frame, standing in for the aircraft camera.

Reads one frame per timer tick and publishes it -- the file is never decoded
ahead of time, so downstream nodes see the same one-frame-at-a-time stream they
would get from real hardware.
"""

import cv2
import rclpy
from cv_bridge import CvBridge
from rclpy.node import Node
from sensor_msgs.msg import Image


class VideoPublisher(Node):
    def __init__(self):
        super().__init__("video_publisher")
        self.declare_parameter("video_path", "")
        self.declare_parameter("frame_id", "camera")
        self.declare_parameter("loop", True)
        self.declare_parameter("fps", 0.0)   # 0 -> use the file's own rate

        path = self.get_parameter("video_path").value
        if not path:
            raise RuntimeError("video_path parameter is required")

        self.cap = cv2.VideoCapture(path)
        if not self.cap.isOpened():
            raise RuntimeError(f"could not open video: {path}")

        fps = self.get_parameter("fps").value or self.cap.get(cv2.CAP_PROP_FPS) or 30.0
        self.loop = self.get_parameter("loop").value
        self.frame_id = self.get_parameter("frame_id").value
        self.bridge = CvBridge()
        self.pub = self.create_publisher(Image, "image_raw", 10)
        self.count = 0

        w = int(self.cap.get(cv2.CAP_PROP_FRAME_WIDTH))
        h = int(self.cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
        self.get_logger().info(f"publishing {path} ({w}x{h}) at {fps:.2f} fps")
        self.timer = self.create_timer(1.0 / fps, self.tick)

    def tick(self):
        ok, frame = self.cap.read()
        if not ok:
            if not self.loop:
                self.get_logger().info("end of video; shutting down")
                self.timer.cancel()
                rclpy.shutdown()
                return
            self.cap.set(cv2.CAP_PROP_POS_FRAMES, 0)
            ok, frame = self.cap.read()
            if not ok:
                return

        msg = self.bridge.cv2_to_imgmsg(frame, encoding="bgr8")
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self.frame_id
        self.pub.publish(msg)
        self.count += 1
        if self.count % 100 == 0:
            self.get_logger().info(f"published {self.count} frames")


def main(args=None):
    rclpy.init(args=args)
    node = VideoPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.cap.release()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
