#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  fs::create_directories("sandbox/a");
  std::ofstream("sandbox/file1.txt");
  std::ofstream("sandbox/file2.txt");
  for (auto& p : fs::directory_iterator("sandbox")) {
    std::cout << p.path() << '\n';
  }
  fs::remove_all("sandbox");
}