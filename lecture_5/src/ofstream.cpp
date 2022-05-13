#include <fstream>
#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main() {
  string filename = "../out.txt";
  std::ofstream outfile(filename);
  if (!outfile.is_open()) {
    return EXIT_FAILURE;
  }
  double a = 1.123123123;
  outfile << "Just string" << endl;
  outfile << std::setprecision(20) << a << endl;
  return 0;
}