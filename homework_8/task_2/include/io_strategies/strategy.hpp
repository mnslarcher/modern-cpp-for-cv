#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_

#include <array>
#include <string>
#include <vector>

namespace igg {
struct ImageData {
  int rows;
  int cols;
  uint8_t max_val;
  std::vector<std::array<int, 3>> data;
};

class IoStrategy {
 public:
  virtual ImageData ReadFromDisk(const std::string& file_name) = 0;
  virtual bool WriteToDisk(const std::string& file_name, const ImageData& data) = 0;
};
}  // namespace igg

#endif