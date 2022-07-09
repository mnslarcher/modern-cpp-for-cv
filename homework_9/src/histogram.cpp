#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <sstream>
#include <vector>

#include "homework_9.h"

namespace ipb {
Histogram::Histogram(const cv::Mat& descriptors,
                     const BowDictionary& dictionary) {
  cv::Mat vocabulary = dictionary.GetInstance().vocabulary();
  if (descriptors.empty()) {
    data_ = {};
    return;
  }
  data_.resize(vocabulary.rows, 0);
  for (int i = 0; i < descriptors.rows; ++i) {
    float min_distance = FLT_MAX;
    int centroid_id = 0;
    cv::Mat descriptor = descriptors.row(i);
    for (int j = 0; j < vocabulary.rows; ++j) {
      cv::Mat word = vocabulary.row(j);
      float distance = cv::norm(descriptor - word);
      if (min_distance > distance) {
        min_distance = distance;
        centroid_id = j;
      }
    }
    data_[centroid_id] += 1;
  }
}

std::ostream& operator<<(std::ostream& os, const Histogram& histogram) {
  for (int val : histogram.data()) {
    os << val << ", ";
  }
  os << std::endl;
  return os;
}

void Histogram::WriteToCSV(std::string& filename) {
  std::ofstream file(filename);
  for (int val : data_) {
    file << val << std::endl;
  }
  file.close();
}

Histogram Histogram::ReadFromCSV(std::string& filename) {
  std::vector<int> read_data;
  std::ifstream file(filename);
  std::string line;
  int val;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    while (ss >> val) {
      read_data.emplace_back(val);
    }
  }
  file.close();
  return Histogram(read_data);
}
}  // namespace ipb