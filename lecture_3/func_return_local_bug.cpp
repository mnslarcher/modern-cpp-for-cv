#include <iostream>
using namespace std;

int &MultiplyBy10(int num) {  // retval is created
  int retval = 0;
  retval = 10 * num;
  cout << "retval is: " << endl;
  return retval;
}  // retval is destroyed, it's not accessible anymore

int main() {
  int out = MultiplyBy10(10);
  cout << "out is " << out << endl;
  return 0;
}