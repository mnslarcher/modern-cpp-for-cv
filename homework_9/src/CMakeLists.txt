add_library(bow_dictionary bow_dictionary.cpp kmeans.cpp)
add_library(histogram histogram.cpp)
target_link_libraries(histogram ${OpenCV_LIBS})
target_link_libraries(bow_dictionary histogram ${OpenCV_LIBS})