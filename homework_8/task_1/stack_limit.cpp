#include <iostream>
#include <numeric>

int main() {
  size_t size = 102400;
  int i = 1;
  while (true) {
    std::byte data[size * i];
    std::cerr << i * 100 << "[KiB] Allocated in the stack" << std::endl;
    i += 1;
  }
  return 0;
}