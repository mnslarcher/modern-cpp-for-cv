#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

int main() {
  using Matf = cv::Mat_<float>;
  Matf image = Matf::zeros(10, 10);
  image.at<float>(5, 5) = 42.42f;
  std::string f = "../outputs/test.exr";
  cv::imwrite(f, image);
  Matf copy = cv::imread(f, cv::IMREAD_UNCHANGED);
  std::cout << copy.at<float>(5, 5) << std::endl;
  return 0;
}