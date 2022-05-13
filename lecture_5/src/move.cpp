#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

struct MyClass {
  int id_ = 0;
  std::vector<std::string> names_{"name", "name", "name", "name", "name",
                                  "name", "name", "name", "name"};
};

void copy_swap(MyClass& obj1, MyClass& obj2) {
  MyClass tmp = obj1;
  obj1 = obj2;
  obj2 = tmp;
}

void move_swap(MyClass& obj1, MyClass& obj2) {
  MyClass tmp = std::move(obj1);
  obj1 = std::move(obj2);
  obj2 = std::move(tmp);
}

int main() {
  int a;
  int& a_ref = a;

  a = 2 + 2;

  //   int b = a + 2;

  int&& c = std::move(a);

  string str = "Hello";
  std::vector<string> v;

  v.push_back(str);
  cout << "After copy, str is " << str << endl;

  v.push_back(std::move(str));
  cout << "After move, str is " << str << endl;
}