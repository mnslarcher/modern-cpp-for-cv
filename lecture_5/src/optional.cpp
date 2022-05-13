#include <iostream>
#include <optional>
#include <string>

using std::cout;
using std::endl;

std::optional<std::string> StringFactory(bool create) {
  if (create) {
    return "Modern C++ is Awesome";
  }
  return {};
}

int main() {
  cout << StringFactory(true).value() << '\n';
  cout << StringFactory(false).value_or(":(") << '\n';
}