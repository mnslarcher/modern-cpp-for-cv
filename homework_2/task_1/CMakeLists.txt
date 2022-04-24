cmake_minimum_required(VERSION 3.1)
project(task_1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(src)

include(${CMAKE_SOURCE_DIR}/../cmake/ClangFormat.cmake)
include(${CMAKE_SOURCE_DIR}/../cmake/StaticAnalyzers.cmake)
