#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;
using std::cout;

void demo_exists(const fs::path& p) {
  cout << p;
  if (fs::exists(p))
    cout << " exists\n";
  else
    cout << " does not exist\n";
}
int main() {
  fs::create_directory("sandbox");
  std::ofstream("sandbox/file");
  demo_exists("sandbox/file");
  demo_exists("sandbox/cacho");
  fs::remove_all("sandbox");
}