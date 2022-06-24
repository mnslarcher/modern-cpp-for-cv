#include <iostream>

using std::cout;
using std::endl;

int main() {
  int size = 2;
  int* ptr = nullptr;
  {
    ptr = new int[size];
    ptr[0] = 42;
    ptr[1] = 13;
  }
  for (int i = 0; i < size; ++i) {
    cout << ptr[i] << endl;
  }
  delete[] ptr;
  for (int i = 0; i < size; ++i) {
    cout << ptr[i] << endl;
  }
  return 0;
}