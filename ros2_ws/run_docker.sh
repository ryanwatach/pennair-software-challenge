#!/usr/bin/env bash
# Build the image if needed, then build + launch the ROS graph in a container.
#
#   ./ros2_ws/run_docker.sh                       # grass clip
#   ./ros2_ws/run_docker.sh video:=/workspace/assets/'PennAir 2024 App Dynamic Hard.mp4'
#   ./ros2_ws/run_docker.sh shell                 # drop into a shell instead
set -euo pipefail
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

docker image inspect pennair-ros2 >/dev/null 2>&1 || docker build -t pennair-ros2 "$REPO/ros2_ws"

if [[ "${1:-}" == "shell" ]]; then
    exec docker run --rm -it -v "$REPO":/workspace -w /workspace/ros2_ws pennair-ros2 bash
fi
exec docker run --rm -it -v "$REPO":/workspace -w /workspace/ros2_ws \
    pennair-ros2 ./build_and_run.sh "$@"
