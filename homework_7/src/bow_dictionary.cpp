#include "bow_dictionary.hpp"

#include <opencv2/core/mat.hpp>
#include <vector>

#include "kmeans.hpp"

namespace ipb {
int& BowDictionary::max_iterations() { return max_iterations_; }
int& BowDictionary::size() { return size_; }
std::vector<cv::Mat>& BowDictionary::descriptors() { return descriptors_; }
cv::Mat& BowDictionary::vocabulary() { return vocabulary_; }
int BowDictionary::total_features() const {
  int total_features = 0;
  for (const cv::Mat& desc : descriptors_) {
    total_features += desc.rows;
  }
  return total_features;
}
bool BowDictionary::empty() { return vocabulary_.empty(); }
void BowDictionary::set_max_iterations(int max_iterations) {
  max_iterations_ = max_iterations;
}
void BowDictionary::set_size(int size) { size_ = size; }
void BowDictionary::set_descriptors(const std::vector<cv::Mat>& descriptors) {
  descriptors_ = descriptors;
}
void BowDictionary::set_params(int max_iterations, int size,
                               const std::vector<cv::Mat>& descriptors) {
  set_max_iterations(max_iterations);
  set_size(size);
  set_descriptors(descriptors);
  vocabulary_ = kMeans(descriptors, size_, max_iterations_);
}

BowDictionary& BowDictionary::GetInstance() {
  static BowDictionary instance;
  return instance;
}
}  // namespace ipb
