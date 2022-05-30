#include <iomanip>
#include <iostream>

class SomeClass {
 public:
  SomeClass();
  SomeClass(int a);
  SomeClass(int a, float b);
  ~SomeClass();
};

SomeClass::SomeClass() {
  std::cout << "Called the constructor with no args" << std::endl;
}
SomeClass::SomeClass(int a) {
  std::cout << "Called the constructor with a = " << a << std::endl;
}
SomeClass::SomeClass(int a, float b) {
  std::cout << "Called the constructor with a = " << a
            << " and b = " << std::setprecision(3) << b << std::endl;
}
SomeClass::~SomeClass() { std::cout << "Called the destructor" << std::endl; }

int main() {
  SomeClass var_1;
  SomeClass var_2(10);
  SomeClass var_3{10};
  SomeClass var_4 = {10};
  SomeClass var_5{10, 10.1};
  SomeClass var_6 = {10, 10.1};
  return 0;
}