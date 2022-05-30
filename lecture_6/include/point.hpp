#include <cmath>

class Point {
 public:
  Point(int x, int y) : x_(x), y_(y) {}
  static float Dist(const Point& a, const Point& b) {
    int diff_x = a.x_ - b.x_;
    int diff_y = a.y_ - b.y_;
    return sqrt(diff_x * diff_x + diff_y * diff_y);
  }

  float Dist(const Point& other) {
    int diff_x = x_ - other.x_;
    int diff_y = y_ - other.y_;
    return sqrt(diff_x * diff_x + diff_y * diff_y);
  }

 private:
  int x_ = 0;
  int y_ = 0;
};