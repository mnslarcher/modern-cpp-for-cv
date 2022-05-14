#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
  string line, file_name;
  std::ifstream input("../inputs/test_bel.txt", std::ios_base::in);
  while (getline(input, line)) {
    cout << "Read: " << line << endl;
    string::size_type loc = line.find("filename", 0);
    if (loc != string::npos) {
      file_name = line.substr(line.find("=", 0) + 2, string::npos);
    }
  }
  cout << "Filename found: " << file_name << endl;
  return 0;
}