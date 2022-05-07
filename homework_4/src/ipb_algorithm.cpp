#include <algorithm>
#include <numeric>
#include <vector>

#include "homework_4.h"

namespace ipb {
using vector = named_vector<int>;

int accumulate(vector& nv) {
  const std::vector<int>& v = nv.vector();
  int out = std::accumulate(v.cbegin(), v.cend(), 0);
  return out;
}

int count(vector& nv, const int& val) {
  const std::vector<int>& v = nv.vector();
  int out = std::count(v.cbegin(), v.cend(), val);
  return out;
}

bool all_even(vector& nv) {
  const std::vector<int>& v = nv.vector();
  return v.end() ==
         std::find_if(v.begin(), v.end(), [](int i) { return i % 2 == 1; });
  //  Alternative:
  // for (int& n : nv.vector()) {
  //   if (n % 2 == 1) {
  //     return false;
  //   }
  // }
  // return true;
}

void clamp(vector& nv, const int& lo, const int& hi) {
  std::vector<int>& v = nv.vector();
  std::transform(v.begin(), v.end(), v.begin(),
                 [=](int val) { return std::clamp(val, lo, hi); });
}

void fill(vector& nv, const int& val) {
  std::vector<int>& v = nv.vector();
  std::fill(v.begin(), v.end(), val);
}

bool find(vector& nv, const int& val) {
  const std::vector<int>& v = nv.vector();
  return v.end() != std::find(v.begin(), v.end(), val);
}

void print(vector& nv) {
  const std::string& n = nv.name();
  const std::vector<int>& v = nv.vector();
  std::for_each(n.begin(), n.end(), [](char c) { std::cout << c; });
  std::cout << " : ";
  for (int i = 0; i < v.size() - 1; ++i) {
    std::cout << v[i] << ", ";
  }
  std::cout << v.back();

  std::cout << std::endl;
}

void toupper(vector& nv) {
  std::string& n = nv.name();
  std::transform(n.begin(), n.end(), n.begin(), ::toupper);
}

void sort(vector& nv) {
  std::vector<int>& v = nv.vector();
  std::sort(v.begin(), v.end());
}

void rotate(vector& nv, const int& by) {
  std::vector<int>& v = nv.vector();
  std::rotate(v.begin(), v.begin() + by, v.end());
}

void reverse(vector& nv) {
  std::vector<int>& v = nv.vector();
  std::reverse(v.begin(), v.end());
}

}  // namespace ipb