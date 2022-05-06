#include <iostream>
using namespace std;

void Counter() {
  static int counter = 0;
  cout << "counter state = " << ++counter << endl;
}

int main() {
  for (size_t i = 0; i < 5; i++) {
    Counter();
  }
  return 0;
}