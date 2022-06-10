cd src

rm -f CMakeLists.txt
touch CMakeLists.txt

for i in *.cpp
do
    echo "add_executable(${i%.*} $i)" >> ../src/CMakeLists.txt
done

cd ..

rm -rf bin
rm -rf build
mkdir build

cd build

cmake ..
make -j 8

cd ../bin

for i in *
do  
    echo "Program: $i\n"
    ./$i
    echo ""
done