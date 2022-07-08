#include <iostream>
#include <typeinfo>

template <class T>
class MyClass {
 public:
  MyClass(T x) : x_(x) {}
  T print() {
    std::cout << "x=" << typeid(x_).name() << std::endl;
    return x_;
  }

 private:
  T x_;
};

int main() {
  MyClass<int> my_float_object(10);
  MyClass<double> my_double_object(10.0);
  my_float_object.print();
  my_double_object.print();
  return 0;
}