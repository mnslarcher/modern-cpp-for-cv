#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;
using std::endl;

int main() {
  std::cout << fs::path("/foo/bar.txt").stem() << endl
            << fs::path("/foo/0000.png").stem() << endl
            << fs::path("/foo/.bar").stem() << endl;
}