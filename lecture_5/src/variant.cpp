#include <iostream>
#include <variant>

using std::cout;
using std::endl;

int main() {
  std::variant<int, float> v1;
  v1 = 12;
  cout << std::get<int>(v1) << endl;
  std::variant<int, float> v2{3.14F};
  cout << std::get<1>(v2) << endl;

  v2 = std::get<int>(v1);
  v2 = std::get<0>(v1);
  v2 = v1;
  cout << std::get<int>(v2) << endl;
}