#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;
using std::vector;

class Rectangle {
 public:
  Rectangle(int w, int h)
      : width_{w}, height_{h} {}  // List init {} doesn't allow narrowing
  int width() const { return width_; }
  int height() const { return height_; }

  virtual void Print() const {
    cout << "Rec: " << width_ << " " << height_ << endl;
  }

 protected:
  int width_ = 0;
  int height_ = 0;
};

class Square : public Rectangle {
 public:
  // explicit specify that cannot be used for implicit conversions and
  // copy-initialization.
  // Implicit conversion is when, for example, b is converted to the type of a
  // when there is an expression like a == b;
  explicit Square(int size) : Rectangle{size, size} {}
  void Print() const override {
    cout << "Sq: " << width_ << " " << height_ << endl;
  }
};

void PrintShape(const Rectangle& rec) { rec.Print(); }

int main() {
  Square sq(10);
  Rectangle rec(10, 15);

  PrintShape(rec);
  PrintShape(sq);

  vector<unique_ptr<Rectangle>> shapes;
  shapes.emplace_back(make_unique<Rectangle>(10, 15));
  shapes.emplace_back(make_unique<Square>(10));

  for (const auto& shape : shapes) {
    shape->Print();
  }

  return 0;
}