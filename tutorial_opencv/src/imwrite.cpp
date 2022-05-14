#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main() {
  cv::Mat image = cv::imread("../inputs/logo_opencv.png", cv::IMREAD_GRAYSCALE);
  cv::imwrite("../outputs/copy.jpg", image);
  return 0;
}