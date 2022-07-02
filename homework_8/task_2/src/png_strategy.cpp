

#include "png_strategy.hpp"

#include <bits/stdint-uintn.h>

#include <array>
#include <fstream>
#include <ios>
#include <iostream>
#include <png++/png.hpp>
#include <string>
#include <vector>

namespace igg {
ImageData PngIoStrategy::ReadFromDisk(const std::string& file_name) {
  png::image<png::rgb_pixel> image(file_name);
  ulong rows = image.get_height();
  ulong cols = image.get_width();
  uint8_t max_val = 0;
  std::vector<std::array<int, 3>> data;
  data.resize(rows * cols);

  for (png::uint_32 row = 0; row < rows; ++row) {
    for (png::uint_32 col = 0; col < cols; ++col) {
      png::rgb_pixel pixel = image.get_pixel(col, row);
      std::array<int, 3> array = {pixel.red, pixel.green, pixel.blue};
      data[row * cols + col] = array;
    }
  }
  return {static_cast<int>(rows), static_cast<int>(cols), max_val, data};
}

bool PngIoStrategy::WriteToDisk(const std::string& file_name,
                                const ImageData& data) {
  png::image<png::rgb_pixel> image(data.cols, data.rows);
  for (png::uint_32 row = 0; row < data.rows; ++row) {
    for (png::uint_32 col = 0; col < data.cols; ++col) {
      int red = data.data[row * data.cols + col][0];
      int green = data.data[row * data.cols + col][1];
      int blue = data.data[row * data.cols + col][2];
      image[row][col] = png::rgb_pixel(red, green, blue);
    }
  }
  image.write(file_name);
  return 1;
}
}  // namespace igg
