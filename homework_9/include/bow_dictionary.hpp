#ifndef BOWDICTIONARY_HPP_
#define BOWDICTIONARY_HPP_

#include <opencv2/core.hpp>
#include <vector>

namespace ipb {
class BowDictionary {
 private:
  cv::Mat vocabulary_;
  BowDictionary() = default;

 public:
  BowDictionary(const BowDictionary&) = delete;
  void operator=(const BowDictionary&) = delete;
  BowDictionary(const BowDictionary&&) = delete;
  void operator=(const BowDictionary&&) = delete;

  static BowDictionary& GetInstance() {
    static BowDictionary instance;
    return instance;
  }

  void build(int max_iterations, int size,
             const std::vector<cv::Mat>& descriptors);

  cv::Mat vocabulary() { return vocabulary_; }

  int size() const { return vocabulary_.rows; }

  void set_vocabulary(cv::Mat vocabulary) { vocabulary_ = vocabulary; }

  bool empty() const {
    if (size() == 0) {
      return true;
    }
    return false;
  }
};
}  // namespace ipb

#endif  // BOWDICTIONARY_HPP_
