#ifndef HISTOGRAM_HPP_
#define HISTOGRAM_HPP_
#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <string>

#include "bow_dictionary.hpp"

namespace ipb {
class Histogram {
 private:
  std::vector<int> data_;

 public:
  Histogram() = default;

  Histogram(std::vector<int>& data) { data_ = data; }

  Histogram(const cv::Mat& descriptors, const BowDictionary& dictionary);

  std::vector<int> data() const { return data_; }

  bool empty() const {
    if (size() == 0) {
      return true;
    }
    return false;
  }

  int size() const { return data_.size(); }

  friend std::ostream& operator<<(std::ostream& os, const Histogram& histogram);

  Histogram& operator=(const Histogram& other) = default;

  int& operator[](int idx) { return data_[idx]; }
  int operator[](int idx) const { return data_[idx]; }

  auto begin() const { return data_.begin(); }
  auto end() const { return data_.end(); }
  auto cbegin() const { return data_.cbegin(); }
  auto cend() const { return data_.cend(); }
  void WriteToCSV(std::string& filename);
  // static -> can be called without an instance of the class
  static Histogram ReadFromCSV(std::string& filename);
};
}  // namespace ipb

#endif