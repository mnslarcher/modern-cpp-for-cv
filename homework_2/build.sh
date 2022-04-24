rm -rf build 
rm -rf bin
mkdir build
mkdir bin
cd build
cmake ..
make
cd ..
bats tests/test_task_1.sh