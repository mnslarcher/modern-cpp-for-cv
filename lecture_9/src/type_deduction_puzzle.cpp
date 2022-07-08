#include <array>
#include <cstdio>

template <typename T, typename U>
void foo(std::array<T, sizeof(U)> x, std::array<U, sizeof(T)> y) {
  puts(__PRETTY_FUNCTION__);
}

int main() {
  foo(std::array<int, 8>{}, std::array<double, 4>{});
  // error because expect 8 (sizeof(double)) and not 9
  // foo(std::array<int, 9>{}, std::array<double, 4>{});
}