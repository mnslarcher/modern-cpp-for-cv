#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

int main() {
  std::string file_name = "../outputs/image.txt";
  std::ofstream file;
  file.open(file_name);
  int rows = 2;
  int cols = 3;
  std::vector<float> vec(rows * cols);
  std::fill(vec.begin(), vec.end(), -100.001);
  file << rows << "\n";
  file << cols << "\n";
  for (int i = 0; i < vec.size(); ++i) {
    file << vec[i] << "\n";
  }
  file.close();
  return 0;
}