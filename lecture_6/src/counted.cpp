#include <iostream>

using std::cout;
using std::endl;

#include "counted.hpp"
int Counted::count = 0;

int main() {
  Counted a, b;
  cout << "Count: " << Counted::count << endl;
  Counted c;
  cout << "Count: " << Counted::count << endl;
  return 0;
}