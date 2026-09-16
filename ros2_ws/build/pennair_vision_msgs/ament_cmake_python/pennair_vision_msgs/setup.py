from setuptools import find_packages
from setuptools import setup

setup(
    name='pennair_vision_msgs',
    version='1.0.0',
    packages=find_packages(
        include=('pennair_vision_msgs', 'pennair_vision_msgs.*')),
)
