rm -rf build
mkdir build

cd build

cmake ..
make

cd ..

./homework_5_test
./main