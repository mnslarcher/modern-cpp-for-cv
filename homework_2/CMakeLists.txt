cmake_minimum_required(VERSION 3.1)
project(homework_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(task_1)

include(${CMAKE_SOURCE_DIR}/cmake/ClangFormat.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)
