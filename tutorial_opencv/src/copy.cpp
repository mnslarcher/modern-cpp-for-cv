#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
  using Matf = cv::Mat_<float>;
  Matf image = Matf::zeros(10, 10);
  Matf image_no_copy = image;
  image_no_copy.at<float>(5, 5) = 42.42f;
  std::cout << image.at<float>(5, 5) << std::endl;
  Matf image_copy = image.clone();
  image_copy.at<float>(1, 1) = 42.42f;
  std::cout << image.at<float>(1, 1) << std::endl;
}