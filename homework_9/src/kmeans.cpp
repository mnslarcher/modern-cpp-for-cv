#include "kmeans.hpp"

#include <opencv2/core.hpp>

namespace ipb {
cv::Mat kMeans(const std::vector<cv::Mat> &descriptors, int k, int max_iter) {
  cv::Mat data;
  cv::Mat labels;
  cv::Mat centers;
  // Each Mat in descriptors refer to an image and have a dimension of 128 times
  // the number of keypoints. This for loop stack the descriptors of each
  // keypoint of every image.
  for (const cv::Mat &desc : descriptors) {
    data.push_back(desc);  // Stack vertically
  }

  cv::kmeans(data, k, labels,
             cv::TermCriteria(cv::TermCriteria::MAX_ITER, max_iter, 0.0), 1,
             cv::KmeansFlags::KMEANS_PP_CENTERS, centers);

  return centers;
}
}  // namespace ipb