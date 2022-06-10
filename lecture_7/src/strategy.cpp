#include <iostream>

using std::cout;
using std::endl;

class Strategy {
 public:
  virtual void Print() const = 0;
};

class StrategyA : public Strategy {
 public:
  void Print() const override { cout << "A" << endl; }
};

class StrategyB : public Strategy {
 public:
  void Print() const override { cout << "B" << endl; }
};

class MyClass {
 public:
  explicit MyClass(const Strategy& s) : strategy_(s) {}
  void Print() const { strategy_.Print(); }

 private:
  const Strategy& strategy_;
};

int main() {
  StrategyA strategy_a = StrategyA();
  StrategyB strategy_b = StrategyB();
  MyClass obj_1(strategy_a);
  MyClass obj_2(strategy_b);
  obj_1.Print();
  obj_2.Print();
  return 0;
}