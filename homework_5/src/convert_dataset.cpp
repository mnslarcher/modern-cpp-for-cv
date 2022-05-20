#include <filesystem>
#include <iostream>
#include <opencv2/opencv.hpp>

#include "homework_5.h"

namespace fs = std::filesystem;

namespace ipb::serialization::sifts {
void ConvertDataset(const fs::path& img_path) {
  fs::path bin_path = fs::canonical(img_path).parent_path() / fs::path("bin");
  if (!fs::exists(bin_path)) {
    fs::create_directory(bin_path);
  }
  for (const fs::directory_entry& dir_entry :
       fs::directory_iterator{img_path}) {
    if (fs::path(dir_entry).extension() == ".png") {
      cv::Mat image = cv::imread(dir_entry.path());
      fs::path file_name = dir_entry.path().filename().stem().string() + ".bin";
      fs::path file_path = bin_path / file_name;
      Serialize(image, file_path);
    }
  }
}
// std::vector<cv::Mat> LoadDataset(const fs::path& bin_path) {}

}  // namespace ipb::serialization::sifts