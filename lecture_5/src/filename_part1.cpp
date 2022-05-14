#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

using std::cout;
using std::endl;

int main() {
  cout << fs::path("/foo/bar.txt").filename() << '\n'
       << fs::path("/foo/.bar").filename() << '\n'
       << fs::path("/foo/bar/").filename() << '\n'
       << fs::path("/foo/.").filename() << '\n'
       << fs::path("/foo/..").filename() << '\n';
}