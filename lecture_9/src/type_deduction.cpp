#include <cstdio>
#include <vector>

template <typename T>
void foo(T x) {
  puts(__PRETTY_FUNCTION__);
}

template <typename T>
struct Foo {
 public:
  Foo(T x) : x_(x) {}
  T x_;
};

int main() {
  foo(4);
  foo(4.2);
  foo("hello");
  auto obj = Foo<int>(10).x_;
  auto same_obj = Foo(10).x_;
  auto vec = std::vector<int>{10, 50};
  auto same_vec = std::vector{10, 50};
}