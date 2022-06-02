rm -rf build
mkdir build

cd build

cmake ..
make -j 48

../bin/homework_6_test