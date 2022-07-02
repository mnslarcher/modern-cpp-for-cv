rm -rf build
mkdir build

cd build

cmake ..
make -j 48

cd ../tests

../bin/task_2_test
