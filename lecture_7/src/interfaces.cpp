#include <iostream>

using std::cout;
using std::endl;

class Printable {
 public:
  virtual void Print() const = 0;
};

class A : public Printable {
 public:
  void Print() const override { cout << "A" << endl; }
};

class B : public Printable {
 public:
  void Print() const override { cout << "B" << endl; }
};

void Print(const Printable& var) { var.Print(); }

int main() {
  Print(A());
  Print(B());
  return 0;
}
