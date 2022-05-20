rm -rf bin
rm -rf build
rm -rf outputs
mkdir build
mkdir outputs

cd build

cmake ..
make

cd ../bin

for i in *
do  
    echo "Program: $i\n"
    ./$i
    echo ""
done