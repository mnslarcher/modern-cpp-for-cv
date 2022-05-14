#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
  cv::Mat image = cv::imread("../inputs/logo_opencv.png", cv::IMREAD_COLOR);
  std::string window_name = "Window name";
  cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
  cv::imshow(window_name, image);
  cv::waitKey(0);
  return 0;
}