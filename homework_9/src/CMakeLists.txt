add_library(bow_dictionary bow_dictionary.cpp)
add_library(kmeans kmeans.cpp)
target_link_libraries(kmeans ${OpenCV_LIBS})
target_link_libraries(bow_dictionary kmeans)