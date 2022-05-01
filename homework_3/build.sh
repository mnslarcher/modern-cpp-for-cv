rm -rf build
rm -rf bin
rm -rf lib
rm web_app/test.html
mkdir build
cd build
cmake ..
make
clear
cd ..
./bin/create_image_browser > web_app/test.html
# opens a file or URL in the user's preferred application
xdg-open web_app/test.html
