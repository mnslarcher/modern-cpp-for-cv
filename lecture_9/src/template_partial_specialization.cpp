#include <iostream>

template <typename T>
constexpr bool is_array = false;

template <typename Tp>
constexpr bool is_array<Tp[]> = true;

int main() {
  std::cout << std::boolalpha;
  std::cout << is_array<int> << std::endl << is_array<int[]> << std::endl;
}