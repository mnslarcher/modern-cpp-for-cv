#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
  // Print how many parameters we received
  cout << "Got " << argc << " params\n";

  // First program argument is always the program name
  cout << "Program: " << argv[0] << endl;

  // cout << argv[1] << endl;
  for (int i = 1; i < argc; i++) {  // from 1 on
    cout << "argv[" << i << "]: " << argv[i] << endl;
  }
  return 0;
}