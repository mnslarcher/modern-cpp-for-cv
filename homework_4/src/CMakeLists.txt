add_library(ipb_algorithm ipb_algorithm.cpp)
add_executable(main main.cpp)
target_link_libraries(main ipb_algorithm)