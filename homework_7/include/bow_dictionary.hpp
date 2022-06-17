#ifndef BOWDICTIONARY_HPP_
#define BOWDICTIONARY_HPP_

#include <opencv2/core/mat.hpp>
#include <vector>

namespace ipb {
class BowDictionary {
 private:
  BowDictionary() = default;
  ~BowDictionary() = default;
  int max_iterations_;
  int size_;
  std::vector<cv::Mat> descriptors_;
  cv::Mat vocabulary_;

 public:
  BowDictionary(const BowDictionary&) = delete;
  void operator=(const BowDictionary&) = delete;
  BowDictionary(const BowDictionary&&) = delete;
  void operator=(const BowDictionary&&) = delete;

  int& max_iterations();
  int& size();
  std::vector<cv::Mat>& descriptors();
  cv::Mat& vocabulary();
  int total_features() const;
  bool empty();
  void set_max_iterations(int max_iterations);
  void set_size(int size);
  void set_descriptors(const std::vector<cv::Mat>& descriptors);
  void set_params(int max_iterations, int size,
                  const std::vector<cv::Mat>& descriptors);

  static BowDictionary& GetInstance();
};
}  // namespace ipb

#endif  // BOWDICTIONARY_HPP_
