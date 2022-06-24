#include <iostream>
using std::cout;
using std::endl;

int main() {
  int a = 42;
  int* a_ptr = &a;
  int b = *a_ptr;
  cout << "a = " << a << " b = " << b << endl;
  *a_ptr = 13;
  cout << "a = " << a << " b = " << b << endl;
  return 0;
}