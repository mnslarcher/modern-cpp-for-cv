#ifndef BOWDICTIONARY_HPP_
#define BOWDICTIONARY_HPP_

#include <opencv2/core/mat.hpp>
#include <vector>

namespace ipb {
class BowDictionary {
 private:
  BowDictionary() = default;
  ~BowDictionary() = default;
  cv::Mat vocabulary_;

 public:
  BowDictionary(const BowDictionary&) = delete;
  void operator=(const BowDictionary&) = delete;
  BowDictionary(const BowDictionary&&) = delete;
  void operator=(const BowDictionary&&) = delete;
  int& size();
  cv::Mat& vocabulary();
  bool empty();
  void set_vocabulary(cv::Mat vocabulary);
  void build(int max_iterations, int size,
             const std::vector<cv::Mat>& descriptors);

  static BowDictionary& GetInstance();
};
}  // namespace ipb

#endif  // BOWDICTIONARY_HPP_
