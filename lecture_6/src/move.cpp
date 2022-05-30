#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

void Print(const string& str) { cout << "lvalue: " << str << endl; }
void Print(std::string&& str) { cout << "rvalue: " << str << endl; }

int main() {
  string hello = "hi";
  Print(hello);
  Print("world");
  Print(std::move(hello));

  string str = "Hello";
  std::vector<string> v;

  v.push_back(str);
  cout << "After copy, str is " << str << endl;
  v.push_back(std::move(str));
  cout << "After move, str is " << str << endl;
  return 0;
}