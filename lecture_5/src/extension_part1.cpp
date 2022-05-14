#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  std::cout << fs::path("/foo/bar.txt").extension() << '\n'
            << fs::path("/foo/bar.").extension() << '\n'
            << fs::path("/foo/bar").extension() << '\n'
            << fs::path("/foo/bar.png").extension() << '\n';
}