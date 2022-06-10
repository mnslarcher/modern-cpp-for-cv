#include <iostream>

using std::cout;
using std::endl;

class Rectangle {
 public:
  Rectangle(int w, int h)
      : width_{w}, height_{h} {}  // List init {} doesn't allow narrowing
  int width() const { return width_; }
  int height() const { return height_; }

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
};

int main() {
  Square sq(10);
  cout << sq.width() << " " << sq.height() << endl;
  return 0;
}