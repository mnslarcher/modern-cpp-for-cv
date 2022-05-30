#include <iostream>
#include <vector>

class Human {
 public:
  Human() {}
  Human(int kindness) : kindness_(kindness) {}
  int kindness(void) const { return kindness_; }

 private:
  int kindness_ = 100;
};

std::ostream& operator<<(std::ostream& os, const Human& human) {
  os << "This human is this kind: " << human.kindness();
  return os;
}

int main() {
  std::vector<Human> humans = {Human{10}, {Human{}}};
  for (auto&& human : humans) {
    std::cout << human << std::endl;
  }
  return 0;
}