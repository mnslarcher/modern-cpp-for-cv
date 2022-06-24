#include <iostream>

using std::cout;
using std::endl;

int main() {
  int *ptr_1 = nullptr;
  int *ptr_2 = nullptr;

  ptr_1 = new int;
  ptr_2 = new int;
  cout << "1: " << ptr_1 << " 2: " << ptr_2 << endl;

  ptr_2 = ptr_1;

  cout << "1: " << ptr_1 << " 2: " << ptr_2 << endl;

  delete ptr_1;
  delete ptr_2;
  return 0;
}