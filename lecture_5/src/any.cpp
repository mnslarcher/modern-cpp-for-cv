#include <any>
#include <iostream>

using std::cout;
using std::endl;

int main() {
  std::any a;
  a = 1;
  cout << std::any_cast<int>(a) << endl;

  a = 3.14;
  cout << std::any_cast<double>(a) << endl;

  a = true;
  cout << std::boolalpha << std::any_cast<bool>(a) << endl;
}