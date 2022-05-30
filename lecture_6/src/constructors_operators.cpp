#include <iostream>

using std::cout;
using std::endl;

class MyClass {
 public:
  MyClass() { cout << "default" << endl; }
  MyClass(const MyClass& other) { cout << "copy" << endl; }
  MyClass(MyClass&& other) { cout << "move" << endl; }
  MyClass& operator=(const MyClass& other) {
    cout << "copy operator" << endl;
    return *this;
  }
  MyClass& operator=(MyClass&& other) {
    cout << "move operator" << endl;
    return *this;
  }
};

int main() {
  MyClass a;
  MyClass b = a;
  a = b;
  MyClass c = std::move(a);
  c = std::move(b);
}