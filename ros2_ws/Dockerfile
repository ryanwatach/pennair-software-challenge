# ROS 2 Jazzy + OpenCV, for running the shape detector as ROS nodes.
#
# The repository is mounted at /workspace rather than copied in, so the nodes
# import the very same detector.py the standalone scripts use.
FROM ros:jazzy-ros-base

SHELL ["/bin/bash", "-c"]

RUN apt-get update && apt-get install -y --no-install-recommends \
        python3-opencv \
        python3-numpy \
        ros-jazzy-cv-bridge \
        ros-jazzy-vision-opencv \
    && rm -rf /var/lib/apt/lists/*

# Let the ROS nodes import the repo's own src/ (detector.py, camera.py).
ENV PYTHONPATH=/workspace/src${PYTHONPATH:+:${PYTHONPATH}}
# No display in the container, and no GPU either.
ENV QT_QPA_PLATFORM=offscreen
ENV OPENCV_VIDEOIO_PRIORITY_INTEL_MFX=0

WORKDIR /workspace/ros2_ws

# Source the overlay automatically for interactive shells.
RUN echo 'source /opt/ros/jazzy/setup.bash' >> /root/.bashrc && \
    echo '[ -f /workspace/ros2_ws/install/setup.bash ] && source /workspace/ros2_ws/install/setup.bash' >> /root/.bashrc

CMD ["bash"]
