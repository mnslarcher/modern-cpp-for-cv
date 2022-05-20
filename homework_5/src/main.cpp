#include <opencv2/opencv.hpp>

#include "homework_5.h"

int main() {
  ipb::serialization::sifts::ConvertDataset("../data/freiburg/images");
  cv::Mat original = cv::imread("../data/lenna.png", cv::IMREAD_COLOR);
  ipb::serialization::Serialize(original, "../outputs/lenna.bin");
  cv::Mat deserialized =
      ipb::serialization::Deserialize("../outputs/lenna.bin");
  cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Deserialized", cv::WINDOW_AUTOSIZE);
  cv::imshow("Original", original);
  cv::imshow("Deserialized", deserialized);
  cv::waitKey(0);
  return 0;
}