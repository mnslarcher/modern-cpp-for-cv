#include <iostream>

using std::cout;
using std::endl;

int main() {
  int size = 5;
  int *ptr_1 = new int[size];
  int *ptr_2 = ptr_1;
  ptr_1[0] = 100;
  cout << "1: " << ptr_1 << " 2: " << ptr_2 << endl;
  delete[] ptr_1;
  ptr_1 = nullptr;
  cout << "1: " << ptr_1 << " 2: " << ptr_2 << endl;
  cout << "ptr_2[0]: " << ptr_2[0] << endl;
  return 0;
}