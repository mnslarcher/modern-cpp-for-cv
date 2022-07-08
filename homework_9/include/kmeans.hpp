#ifndef KMEANS_HPP_
#define KMEANS_HPP_

#include <opencv2/core/mat.hpp>
#include <vector>

namespace ipb {
cv::Mat kMeans(const std::vector<cv::Mat>& descriptors, int k, int max_iter);
}  // namespace ipb

#endif  // KMEANS_HPP_