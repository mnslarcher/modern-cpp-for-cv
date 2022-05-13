#include <chrono>
#include <iostream>

using std::cout;
using std::endl;

int fibonacci(const int &n) {
  if (n < 2) return n;
  int f0 = 0;
  int f1 = 1;
  int fn;
  for (int i = 2; i <= n; ++i) {
    fn = f0 + f1;
    f0 = f1;
    f1 = fn;
  }
  return fn;
}

int main() {
  auto start = std::chrono::steady_clock::now();
  cout << "f(42) = " << fibonacci(42) << endl;
  auto end = std::chrono::steady_clock::now();

  std::chrono::duration<double> sec = end - start;
  cout << "elapsed time: " << sec.count() << "s\n";
}