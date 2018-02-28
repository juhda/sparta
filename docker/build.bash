#!/bin/bash
# build the odroid linux image

make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- odroidxu3_defconfig
make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-
make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules
