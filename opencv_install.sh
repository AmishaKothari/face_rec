#!/bin/bash

# Update the system
echo "updating ..."
apt update

# Upgrade the system
echo "upgrading ..."
apt upgrade

# Install dependecies
echo "installing dependencies ..."
apt-get install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
apt-get install python3.6-dev python3-numpy libtbb2 libtbb-dev
apt-get install libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev
apt-get install libopencv-dev

# Clone repositories
echo "cloning opencv repositories ..."
rm -rf /opt/opencv
rm -rf /opt/opencv_contrib
cd /opt && \
git clone https://github.com/Itseez/opencv.git && \
git clone https://github.com/Itseez/opencv_contrib.git

# Install opencv
echo "installing opencv ..."
mkdir /opt/opencv/release

cd /opt/opencv/release && \ 
cmake -D BUILD_TIFF=ON -D WITH_CUDA=OFF -D ENABLE_AVX=OFF -D WITH_OPENGL=OFF -D WITH_OPENCL=OFF -D WITH_IPP=OFF -D WITH_TBB=ON -D BUILD_TBB=ON -D WITH_EIGEN=OFF -D WITH_V4L=OFF -D WITH_VTK=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules /opt/opencv/ &&\
make -j4 && \
make install && \

ldconfig

echo "Congratulations.. It's DONE.....!!!!!!!!!"
echo "Run 'pkg-config --modversion opencv' to check if properly installed"	