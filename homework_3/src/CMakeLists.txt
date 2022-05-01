include_directories(${PROJECT_SOURCE_DIR}/api)

add_library(html_writer html_writer.cpp)
add_executable(main main.cpp)
target_link_libraries(main html_writer fmt)


