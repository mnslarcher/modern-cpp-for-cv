

#include "ppm_strategy.hpp"

#include <bits/stdint-uintn.h>

#include <array>
#include <fstream>
#include <ios>
#include <iostream>
#include <png++/png.hpp>
#include <string>

namespace igg {
ImageData PpmIoStrategy::ReadFromDisk(const std::string& file_name) {
  std::ifstream in(file_name, std::ios_base::in);
  // Read meta data
  std::string type;
  int rows = 0;
  int cols = 0;
  int max_val = 0;
  std::vector<std::array<int, 3>> data;
  in >> type;

  // Ignore comment line
  std::string dummy;
  in >> dummy;
  if (!dummy.compare("#")) {
    in.ignore(256, '\n');
    in >> rows;
  } else {
    rows = std::stoi(dummy);
  };

  in >> cols >> max_val;

  // Read data
  data.resize(rows * cols);
  int red = 0;
  int green = 0;
  int blue = 0;
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      in >> red >> green >> blue;
      data[r * cols + c] = {red, green, blue};
    }
  }
  return {rows, cols, static_cast<uint8_t>(max_val), data};
}

bool PpmIoStrategy::WriteToDisk(const std::string& file_name,
                                const ImageData& data) {
  std::ofstream out(file_name);
  if (!out) {
    return false;
  }

  out << "P3" << std::endl
      << data.rows << " " << data.cols << std::endl
      << data.max_val << std::endl;
  for (int r = 0; r < data.rows; ++r) {
    for (int c = 0; c < data.cols; ++c) {
      out << data.data[r * data.cols + c][0] << " ";
      out << data.data[r * data.cols + c][1] << " ";
      out << data.data[r * data.cols + c][2] << " ";
    }
    out << std::endl;
  }
  return true;
}
}  // namespace igg
