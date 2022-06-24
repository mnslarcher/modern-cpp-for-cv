#include <iostream>
#include <vector>

using std::cout;

struct AbstractShape {
  virtual void Print() const = 0;
};

struct Square : public AbstractShape {
  void Print() const override { cout << "Square\n"; }
};

struct Triangle : public AbstractShape {
  void Print() const override { cout << "Triangle\n"; }
};

int main() {
  std::vector<AbstractShape*> shapes;
  Square square;
  Triangle triangle;
  shapes.push_back(&square);
  shapes.push_back(&triangle);
  for (const auto& shape : shapes) {
    shape->Print();
  }
  return 0;
}