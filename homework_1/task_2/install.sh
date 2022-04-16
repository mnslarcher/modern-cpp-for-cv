#!/usr/bin/env bash
rm -rf install
mkdir install
rm -rf build
mkdir build
cd build
cmake ..
make install
