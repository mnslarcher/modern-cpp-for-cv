#ifndef COUNTED_HPP_
#define COUNTED_HPP_

class Counted {
 public:
  Counted() { Counted::count++; }
  ~Counted() { Counted::count--; }
  static int count;
};

#endif  // COUNTED_HPP_