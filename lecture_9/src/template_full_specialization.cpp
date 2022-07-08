#include <iostream>

template <typename T>
bool is_void() {
  return false;
}

template <>
bool is_void<void>() {
  return true;
}

int main() {
  std::cout << std::boolalpha << is_void<int>() << std::endl
            << is_void<void>() << std::endl;
}