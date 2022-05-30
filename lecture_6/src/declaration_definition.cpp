#include <iostream>

class SomeClass {
 public:
  SomeClass();
  int var() const;

 private:
  void DoSmth();
  int var_ = 0;
};

SomeClass::SomeClass() {}
int SomeClass::var() const { return var_; }
void SomeClass::DoSmth() {}

int main() {
  SomeClass some_class = SomeClass();
  std::cout << "var: " << some_class.var() << std::endl;
}