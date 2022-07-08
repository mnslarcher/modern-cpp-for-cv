#include <iostream>

template <typename T>
T abs(T x) {
  return (x >= 0) ? x : -x;
}

int main() {
  const double x = 5.5;
  const int y = -5;

  auto abs_x = abs<double>(x);
  int abs_y = abs<int>(y);

  double abs_x_2 = abs(x);
  auto abs_y_2 = abs(y);

  std::cout << "abs_x=" << abs_x << " abs_y=" << abs_y << " abs_x_2=" << abs_x_2
            << " abs_y_2=" << abs_y_2 << std::endl;
}