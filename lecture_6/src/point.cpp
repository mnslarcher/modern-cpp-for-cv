#include "point.hpp"

#include <iostream>
using std::cout;
using std::endl;

int main() {
  Point p1(2, 2);
  Point p2(1, 1);
  cout << "Dist is " << Point::Dist(p1, p2) << endl;
  cout << "Dist is " << p1.Dist(p2) << endl;
}