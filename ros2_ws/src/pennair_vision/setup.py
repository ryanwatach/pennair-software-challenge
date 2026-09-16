from setuptools import setup

package_name = "pennair_vision"

setup(
    name=package_name,
    version="1.0.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        ("share/" + package_name + "/launch", ["launch/detection.launch.py"]),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="Ryan Watach",
    maintainer_email="watachryan@gmail.com",
    description="Streams video and detects solid shapes on textured backgrounds.",
    license="MIT",
    entry_points={
        "console_scripts": [
            "video_publisher = pennair_vision.video_publisher:main",
            "detector_node = pennair_vision.detector_node:main",
        ],
    },
)
