#include <filesystem>
#include <iostream>
#include <opencv2/opencv.hpp>

#include "homework_5.h"

namespace fs = std::filesystem;

namespace ipb::serialization::sifts {
void ConvertDataset(const fs::path& img_path) {
  fs::path bin_path =
      fs::weakly_canonical(img_path).parent_path() / fs::path("bin");
  if (!fs::exists(bin_path)) {
    fs::create_directories(bin_path);
  }
  if (!fs::exists(img_path)) {
    return;
  }
  for (const fs::directory_entry& dir_entry :
       fs::directory_iterator{img_path}) {
    if (fs::path(dir_entry).extension() == ".png") {
      // Reading the original image and declaring keypoints and descriptor
      cv::Mat image = cv::imread(dir_entry.path());
      std::vector<cv::KeyPoint> keypoints;
      cv::Mat descriptor;
      // Creating the detector and the extractor
      auto detector = cv::SiftFeatureDetector::create();
      auto extractor = cv::SiftDescriptorExtractor::create();
      // Detecting the keypoints
      detector->detect(image, keypoints);
      // Extracting the descriptor
      extractor->compute(image, keypoints, descriptor);

      // Serializing the descriptor
      fs::path file_name = dir_entry.path().filename().stem().string() + ".bin";
      fs::path file_path = bin_path / file_name;
      Serialize(descriptor, file_path);
    }
  }
}

std::vector<cv::Mat> LoadDataset(const fs::path& bin_path) {
  std::vector<cv::Mat> dataset;
  cv::Mat descriptor;
  for (const fs::directory_entry dir_entry : fs::directory_iterator{bin_path}) {
    if (dir_entry.path().extension() == ".bin") {
      descriptor = Deserialize(dir_entry.path());
      dataset.push_back(descriptor);
    }
  }
  return dataset;
}

}  // namespace ipb::serialization::sifts