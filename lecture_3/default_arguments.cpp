#include <iostream>
using namespace std;

string SayHello(const string& to_whom = "world") {
  return "Hello " + to_whom + "!";
}

int main() {
  cout << SayHello() << endl;

  cout << SayHello("students") << endl;
  return 0;
}