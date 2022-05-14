#include <fstream>
#include <iostream>
#include <string>

using std::string;
using Mode = std::ios_base::openmode;
using std::cout;
using std::endl;

int main() {
  std::ifstream f_in(string & file_name, Mode mode);
  std::ofstream f_out(string & file_name, Mode mode);
  std::fstream f_in_out(string & file_name, Mode mode);

  int i;
  double a, b;
  string s;
  std::ifstream in("../inputs/test_cols.txt", std::ios_base::in);
  while (in >> i >> a >> s >> b) {
    cout << i << ", " << a << ", " << s << ", " << b << endl;
  }
  return 0;
}