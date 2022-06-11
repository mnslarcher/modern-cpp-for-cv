#include <opencv2/core/mat.hpp>
#include <vector>

namespace ipb {
cv::Mat kMeans(const std::vector<cv::Mat>& descriptors, int k, int max_iter);
}