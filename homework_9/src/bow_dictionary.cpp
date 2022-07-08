#include "bow_dictionary.hpp"

#include <opencv2/core/mat.hpp>
#include <vector>

#include "kmeans.hpp"

namespace ipb {
int& BowDictionary::size() { return vocabulary_.rows; }
cv::Mat& BowDictionary::vocabulary() { return vocabulary_; }
bool BowDictionary::empty() { return vocabulary_.empty(); }
void BowDictionary::set_vocabulary(cv::Mat vocabulary) {
  vocabulary_ = vocabulary;
}
void BowDictionary::build(int max_iterations, int size,
                          const std::vector<cv::Mat>& descriptors) {
  vocabulary_ = kMeans(descriptors, size, max_iterations);
}

BowDictionary& BowDictionary::GetInstance() {
  static BowDictionary instance;
  return instance;
}
}  // namespace ipb
