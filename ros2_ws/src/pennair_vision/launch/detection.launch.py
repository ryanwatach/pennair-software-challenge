"""Bring up the camera stream and the detector together.

    ros2 launch pennair_vision detection.launch.py video:=/path/to/clip.mp4
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    video = LaunchConfiguration("video")
    loop = LaunchConfiguration("loop")
    estimate_3d = LaunchConfiguration("estimate_3d")

    return LaunchDescription([
        DeclareLaunchArgument(
            "video",
            default_value="/workspace/assets/PennAir 2024 App Dynamic.mp4",
            description="video file to stream as the camera feed"),
        DeclareLaunchArgument(
            "loop", default_value="true",
            description="restart the clip when it ends"),
        DeclareLaunchArgument(
            "estimate_3d", default_value="true",
            description="report 3D centers using the circle for scale"),

        Node(
            package="pennair_vision",
            executable="video_publisher",
            name="video_publisher",
            output="screen",
            parameters=[{"video_path": video, "loop": loop}],
            # Both nodes sit in /camera, so image_raw resolves to the same
            # topic for publisher and subscriber without any remapping.
            namespace="camera",
        ),
        Node(
            package="pennair_vision",
            executable="detector_node",
            name="shape_detector",
            output="screen",
            parameters=[{"estimate_3d": estimate_3d}],
            namespace="camera",
        ),
    ])
