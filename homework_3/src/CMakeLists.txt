include_directories(${PROJECT_SOURCE_DIR}/api)

add_library(homework_3 html_writer.cpp image_browser.cpp)
add_executable(create_image_browser create_image_browser.cpp)
target_link_libraries(create_image_browser homework_3 fmt)


