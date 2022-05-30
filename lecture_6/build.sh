cd src

rm -f CMakeLists.txt
touch CMakeLists.txt

echo "include_directories(../include)" >> ../src/CMakeLists.txt

for i in *.cpp
do
    echo "add_executable(${i%.*} $i)" >> ../src/CMakeLists.txt
    # if test -f "../include/${i%.*}.hpp"
    # then
    #     echo "target_link_libraries(${i%.*} ${i%.*}.hpp)" >> ../src/CMakeLists.txt
    # fi
done

cd ..

rm -rf bin
rm -rf build
mkdir build

cd build

cmake ..
make -j 48

cd ../bin

for i in *
do  
    echo "Program: $i\n"
    ./$i
    echo ""
done