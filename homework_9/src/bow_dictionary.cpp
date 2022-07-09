#include "bow_dictionary.hpp"

#include <opencv2/core/mat.hpp>
#include <vector>

#include "kmeans.hpp"

void ipb::BowDictionary::build(int max_iterations, int size,
                               const std::vector<cv::Mat>& descriptors) {
  vocabulary_ = kMeans(descriptors, size, max_iterations);
}
