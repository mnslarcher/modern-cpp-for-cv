#include "serialize.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

namespace fs = std::filesystem;

namespace ipb::serialization {
void Serialize(const cv::Mat& mat, const std::string& filename) {
  std::ofstream out(filename, std::ios_base::out | std::ios_base::binary);
  int rows = mat.rows;
  int cols = mat.cols;
  int type = mat.type();
  out.write(reinterpret_cast<char*>(&rows), sizeof(rows));
  out.write(reinterpret_cast<char*>(&cols), sizeof(cols));
  out.write(reinterpret_cast<char*>(&type), sizeof(type));
  if (mat.isContinuous()) {
    out.write(mat.ptr<char>(0), mat.dataend - mat.datastart);
  } else {
    int rows_size = CV_ELEM_SIZE(type) * mat.cols;
    for (int row = 0; row < rows; ++row) {
      out.write(mat.ptr<char>(row), rows_size);
    }
  }
}
cv::Mat Deserialize(const std::string& filename) {
  std::ifstream in(filename, std::ios_base::in | std::ios_base::binary);
  int rows;
  int cols;
  // int channels;
  int type;
  in.read(reinterpret_cast<char*>(&rows), sizeof(rows));
  in.read(reinterpret_cast<char*>(&cols), sizeof(cols));
  in.read(reinterpret_cast<char*>(&type), sizeof(type));

  cv::Mat mat(rows, cols, type);
  in.read(reinterpret_cast<char*>(mat.data), CV_ELEM_SIZE(type) * rows * cols);

  return mat;
}
}  // namespace ipb::serialization