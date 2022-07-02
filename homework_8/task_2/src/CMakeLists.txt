add_library(strategies png_strategy.cpp ppm_strategy.cpp)
target_link_libraries(strategies ${PNG_LIBRARIES})

add_library(image image.cpp)
target_link_libraries(image strategies)
