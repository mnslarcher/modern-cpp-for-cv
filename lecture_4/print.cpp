#include <array>
#include <iostream>
#include <list>
#include <vector>

void print(const std::array<int, 10> &arr) {
  for (const auto &value : arr) {
    std::cout << value << " ";
  }
  std::cout << std::endl;
}

void print(const std::vector<int> &vec) {
  for (const auto &value : vec) {
    std::cout << value << " ";
  }
  std::cout << std::endl;
}

template <typename Iterator>
void print_it(Iterator begin, Iterator end) {
  for (Iterator it = begin; it != end; it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << "arr: ";
  print(arr);
  std::cout << "vec: ";
  print(vec);

  std::cout << "arr: ";
  print_it(arr.cbegin(), arr.cend());
  std::cout << "vec: ";
  print_it(vec.cbegin(), vec.cend());
  std::cout << "list: ";
  print_it(l.cbegin(), l.cend());
}