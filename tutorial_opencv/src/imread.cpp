#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

int main() {
  cv::Mat i1 = cv::imread("../inputs/logo_opencv.png", cv::IMREAD_GRAYSCALE);
  cv::Mat_<uint8_t> i2 = cv::imread("../inputs/logo_opencv.png", cv::IMREAD_GRAYSCALE);
  std::cout << (i1.type() == i2.type()) << std::endl;
  return 0;
}