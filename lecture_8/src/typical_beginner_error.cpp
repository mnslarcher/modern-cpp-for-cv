#include <iostream>
#include <memory>

int main() {
  int a = 42;
  int* ptr_to_a = &a;
  auto a_unique_ptr = std::unique_ptr<int>(ptr_to_a);
  auto a_shared_ptr = std::shared_ptr<int>(ptr_to_a);

  std::cout << "Program terminated correctly!!!\n";
  return 0;
}