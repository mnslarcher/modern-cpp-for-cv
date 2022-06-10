#include <iostream>

class Singleton {
 private:
  Singleton() = default;
  ~Singleton() = default;

 public:
  Singleton(const Singleton&) = delete;
  void operator=(const Singleton&) = delete;
  Singleton(const Singleton&&) = delete;
  void operator=(const Singleton&&) = delete;

  static Singleton& GetInstance() {
    static Singleton instance;
    return instance;
  }

 private:
  int foo_ = 0;

 public:
  int foo() const { return foo_; }
  void set_foo(int foo) { foo_ = foo; }
};

int main() {
  auto& singleton = Singleton::GetInstance();
  std::cout << singleton.foo() << '\n';
  singleton.set_foo(50);
  std::cout << singleton.foo() << '\n';
  return 0;
}