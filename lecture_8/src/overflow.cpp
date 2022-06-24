#include <iostream>

int main() {
  int ar[] = {1, 2, 3};
  for (int i = 0; i < 6; i++) {
    std::cout << i << ": value: " << ar[i] << "\t addr" << &ar[i] << std::endl;
  }
  return 0;
}