#include <boost/core/demangle.hpp>
#include <iostream>
using boost::core::demangle;
using std::cout;

template <typename T>
class Printable {
 public:
  explicit Printable() { cout << demangle(typeid(T).name()) << " created\n"; };
};

class Example1 : public Printable<Example1> {};
class Example2 : public Printable<Example2> {};
class Example3 : public Printable<Example3> {};

int main() {
  const Example1 obj1;
  const Example2 obj2;
  const Example3 obj3;
  return 0;
}