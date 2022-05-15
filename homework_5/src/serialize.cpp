#include "serialize.hpp"

#include <filesystem>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <string>

namespace fs = std::filesystem;

namespace ipb::serialization {
void Serialize(const cv::Mat& m, const std::string& filename) {
  std::string filename_bin = fs::path(filename).stem();
  filename_bin.append(".bin");
  std::ofstream out(filename_bin, std::ios_base::out | std::ios_base::binary);
  int dims = m.dims, rows = m.rows, cols = m.cols, channels = m.channels();
}
cv::Mat Deserialize(const std::string& filename) {
  int dims = 0, rows = 0, cols = 0, channels = 0;
  std::ifstream in(filename, std::ios_base::in | std::ios_base::binary);
  in.read(reinterpret_cast<char*>(&dims), sizeof(dims));
  in.read(reinterpret_cast<char*>(&rows), sizeof(rows));
  in.read(reinterpret_cast<char*>(&cols), sizeof(cols));
  in.read(reinterpret_cast<char*>(&channels), sizeof(channels));
  cv::Mat Mat::zeros(rows, cols, CV_8UC3);
}
}  // namespace ipb::serialization