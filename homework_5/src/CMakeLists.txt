add_library(mat_serialization serialize.cpp)
target_link_libraries(mat_serialization ${OpenCV_LIBS})