#include <math.h>

#include <algorithm>
#include <cstdint>
#include <vector>

#include "homework_6.h"

namespace igg {
Image::Image() {}

Image::Image(int rows, int cols)
    : rows_(rows), cols_(cols), data_(rows * cols, 0) {}

int Image::cols() const { return cols_; }

int Image::rows() const { return rows_; }

uint8_t& Image::at(int row, int col) { return data_[row * cols_ + col]; }
const uint8_t& Image::at(int row, int col) const {
  return data_[row * cols_ + col];
}

bool Image::FillFromPgm(const std::string& file_name) {
  io_tools::ImageData image_data = io_tools::ReadFromPgm(file_name);
  rows_ = image_data.rows;
  cols_ = image_data.cols;
  data_ = image_data.data;
  return !data_.empty();
}
void Image::WriteToPgm(const std::string& file_name) const {
  uint8_t max_val = *std::max_element(data_.begin(), data_.end());
  io_tools::ImageData image_data{rows_, cols_, max_val, data_};
  io_tools::WriteToPgm(image_data, file_name);
}

std::vector<float> Image::ComputeHistogram(int bins) const {
  std::vector<float> histogram(bins, 0.0);
  for (float val : data_) {
    histogram[val * bins / 256] += 1;
  }
  const float size = data_.size();
  std::transform(histogram.begin(), histogram.end(), histogram.begin(),
                 [size](float val) { return val / size; });
  return histogram;
}

void Image::UpScale(int size) {}

void Image::DownScale(int size) {}
}  // namespace igg