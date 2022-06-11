rm -rf build
mkdir build

cd build

cmake ..
make -j 48

cd ../tests

../bin/test_kmeans
../bin/test_bow_dictionary
