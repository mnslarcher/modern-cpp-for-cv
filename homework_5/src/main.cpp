#include <iostream>
#include <opencv2/opencv.hpp>

#include "homework_5.h"

int main() {
  ipb::serialization::sifts::ConvertDataset("data/freiburg/images");
  std::vector<cv::Mat> dataset =
      ipb::serialization::sifts::LoadDataset("data/freiburg/bin");

  cv::Mat image = cv::imread("data/lenna.png", cv::IMREAD_COLOR);
  std::vector<cv::KeyPoint> keypoints;
  cv::Mat descriptor;
  cv::Mat image_with_keypoints;
  auto detector = cv::SiftFeatureDetector::create();
  auto extractor = cv::SiftDescriptorExtractor::create();
  detector->detect(image, keypoints);
  extractor->compute(image, keypoints, descriptor);
  cv::drawKeypoints(image, keypoints, image_with_keypoints);

  // Serializing the descriptor
  ipb::serialization::Serialize(descriptor, "lenna.bin");
  cv::Mat descriptor_des = ipb::serialization::Deserialize("lenna.bin");
  cv::Mat diff;
  cv::compare(descriptor, descriptor_des, diff, cv::CMP_NE);
  std::cout
      << "Does the descriptor remain the same after Serialize/Deserialize? "
      << std::boolalpha << (cv::countNonZero(diff) == 0) << std::endl;

  cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Image With Keypoints", cv::WINDOW_AUTOSIZE);
  cv::imshow("Image", image);
  cv::imshow("Image With Keypoints", image_with_keypoints);
  cv::waitKey(0);
  return 0;
}