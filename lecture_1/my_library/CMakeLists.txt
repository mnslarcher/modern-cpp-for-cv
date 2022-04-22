cmake_minimum_required(VERSION 3.1)
project(my_library)

add_library(tools tools.cpp)
add_executable(main main.cpp)
target_link_libraries(main tools)
