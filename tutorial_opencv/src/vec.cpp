#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
  cv::Mat mat = cv::Mat::zeros(10, 10, CV_8UC3);
  std::cout << mat.at<cv::Vec3b>(5, 5)  // Vec3b means with 3 bytes entries, BGR
            << std::endl;
  cv::Mat_<cv::Vec3f> matf3 = cv::Mat_<cv::Vec3f>::zeros(10, 10);
  std::cout << matf3.at<cv::Vec3f>(5, 5) << std::endl;
  return 0;
}