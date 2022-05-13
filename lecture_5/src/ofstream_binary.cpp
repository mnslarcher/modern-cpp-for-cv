#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;

int main() {
  string file_name = "../image.dat";
  std::ofstream file(file_name, std::ios_base::out | std::ios_base::binary);
  int rows = 2;
  int cols = 3;
  std::vector<float> vec(rows * cols);
  std::fill(vec.begin(), vec.end(), -100.001);
  file.write(reinterpret_cast<char*>(&rows), sizeof(rows));
  file.write(reinterpret_cast<char*>(&cols), sizeof(cols));
  file.write(reinterpret_cast<char*>(&vec.front()), vec.size() * sizeof(float));
  return 0;
}