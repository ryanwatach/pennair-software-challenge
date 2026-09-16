#!/usr/bin/env bash
# Build the workspace and launch the detection graph, inside the container.
set -euo pipefail
source /opt/ros/jazzy/setup.bash
cd /workspace/ros2_ws
colcon build --symlink-install
source install/setup.bash
exec ros2 launch pennair_vision detection.launch.py "$@"
