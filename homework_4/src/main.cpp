#include <iostream>
#include <string>
#include <vector>

#include "homework_4.h"

using vector = ipb::named_vector<int>;

int main() {
  vector v1{"name", {4, 2, 1, 3}};
  std::cout << ipb::accumulate(v1) << std::endl;
  std::cout << ipb::count(v1, 1) << std::endl;
  vector v2{"other name", {4, 2, 6, 8}};
  std::cout << std::boolalpha << ipb::all_even(v2) << std::endl;
  vector v3{"Grandote", {42, 12, 6, -18}};
  ipb::clamp(v3, 0, 15);
  ipb::print(v3);
  ipb::fill(v3, -99);
  ipb::print(v3);
  std::cout << std::boolalpha << ipb::find(v1, 1) << std::endl;
  vector v4{"Jose Luis", {1, 2, 3, 4}};
  ipb::print(v4);
  ipb::toupper(v4);
  ipb::print(v4);
  vector v5{"any name", {15, 12, 6, 0}};
  ipb::sort(v5);
  ipb::print(v5);
  ipb::rotate(v5, 2);
  ipb::print(v5);
  ipb::reverse(v4);
  ipb::print(v4);
  return 0;
}