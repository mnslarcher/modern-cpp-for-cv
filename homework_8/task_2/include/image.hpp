#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include <memory>
#include <string>
#include <vector>

#include "io_strategies/strategy.hpp"

namespace igg {

class Image {
 public:
  Image();
  Image(int rows, int cols);
  ~Image();
  class Pixel {
   public:
    Pixel() = default;
    Pixel(int r, int g, int b) {
      red = r;
      green = g;
      blue = b;
    }
    Pixel(std::array<int, 3> rgb) {
      red = rgb[0];
      green = rgb[1];
      blue = rgb[2];
    }
    ~Pixel() = default;

   public:
    int red;
    int green;
    int blue;
  };

  int rows() const;
  int cols() const;
  Pixel& at(const int row, const int col);
  const Pixel& at(const int row, const int col) const;

 public:
  bool ReadFromDisk(const std::string& file_name);
  void WriteToDisk(const std::string& file_name) const;
  void SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr);

  std::vector<float> ComputeHistogram(int bins) const;
  void DownScale(int scale);
  void UpScale(int scale);

 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 0;
  std::vector<Pixel> data_;
  std::shared_ptr<IoStrategy> strategy_ptr_ = nullptr;
};
}  // namespace igg

#endif