#include <iostream>
#include <numeric>
#include <vector>
using std::cout;
using std::endl;

template <typename T, size_t N = 10>
T AccumulateVector(const T& val) {
  std::vector<T> vec(val, N);
  return std::accumulate(vec.begin(), vec.end(), 0);
}

int main() {
  cout << AccumulateVector(1) << endl;
  cout << AccumulateVector<float>(2) << endl;
  cout << AccumulateVector<float, 5>(2.0) << endl;
  return 0;
}