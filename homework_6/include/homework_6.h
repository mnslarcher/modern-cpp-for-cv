#ifndef HOMEWORK_6_H_
#define HOMEWORK_6_H_

#include <cstdint>
#include <vector>

#include "io_tools.hpp"

namespace igg {
class Image {
 public:
  Image();
  Image(int rows, int cols);
  int rows() const;
  int cols() const;
  uint8_t& at(int row, int col);
  const uint8_t& at(int row, int col) const;
  bool FillFromPgm(const std::string& file_name);
  void WriteToPgm(const std::string& file_name) const;
  std::vector<float> ComputeHistogram(int bins) const;
  void DownScale(int scale);
  void UpScale(int scale);

 private:
  int rows_ = 0;
  int cols_ = 0;
  std::vector<uint8_t> data_;
};
}  // namespace igg

#endif