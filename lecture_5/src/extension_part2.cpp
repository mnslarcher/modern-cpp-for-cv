#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  std::cout << fs::path("/foo/.").extension() << '\n'
            << fs::path("/foo/..").extension() << '\n'
            << fs::path("/foo/.hidden").extension() << '\n'
            << fs::path("/foo/..bar").extension() << '\n';
}