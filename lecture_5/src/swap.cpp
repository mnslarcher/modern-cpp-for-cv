#include <iostream>
#include <utility>

int main() {
  int a = 3;
  int b = 5;

  std::cout << a << ' ' << b << '\n';

  std::swap(a, b);

  std::cout << a << ' ' << b << '\n';
}