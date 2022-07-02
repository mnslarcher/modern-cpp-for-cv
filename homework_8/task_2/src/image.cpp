#include "image.hpp"

#include <iostream>
#include <string>

namespace igg {
void Image::SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr) {
  strategy_ptr_ = strategy_ptr;
}

bool Image::ReadFromDisk(const std::string& file_name) {
  ImageData data = strategy_ptr_->ReadFromDisk(file_name);
  rows_ = data.rows;
  cols_ = data.cols;
  max_val_ = data.max_val;
  std::vector<Pixel> pixels;

  for (auto pixel : data.data) {
    pixels.push_back(Pixel(pixel));
  }
  data_ = pixels;

  if (rows_ == 0 && cols_ == 0) {
    return false;
  }
  return true;
}

void Image::WriteToDisk(const std::string& file_name) const {
  ImageData data;
  data.rows = rows_;
  data.cols = cols_;
  data.max_val = max_val_;
  std::vector<std::array<int, 3>> rgb_vector;
  for (auto pixel : data_) {
    std::array<int, 3> rgb = {pixel.red, pixel.green, pixel.blue};
    rgb_vector.push_back(rgb);
  }
  data.data = rgb_vector;
  strategy_ptr_->WriteToDisk(file_name, data);
}

Image::Image() {
  rows_ = 0;
  cols_ = 0;
}
Image::Image(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  data_.resize(rows * cols);
}
Image::~Image() {}

int Image::rows() const { return rows_; }
int Image::cols() const { return cols_; }
Image::Pixel& Image::at(const int row, const int col) {
  return data_[row * cols_ + col];
}

const Image::Pixel& Image::at(const int row, const int col) const {
  return data_[row * cols_ + col];
}

void Image::DownScale(int scale) {
  int rows = rows_ / scale;
  int cols = cols_ / scale;
  std::vector<Pixel> data(rows * cols);
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      data[r * cols + c] = data_[r * cols_ * scale + c * scale];
    }
  }
  data_.resize(cols * rows);
  data_ = data;
  rows_ = rows;
  cols_ = cols;
}

void Image::UpScale(int scale) {
  int rows = rows_ * scale;
  int cols = cols_ * scale;
  std::vector<Pixel> data(rows * cols);

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      data[r * cols + c] = data_[r / scale * cols / scale + c / scale];
    }
  }

  data_.resize(cols * rows);
  data_ = data;
  rows_ = rows;
  cols_ = cols;
}

}  // namespace igg