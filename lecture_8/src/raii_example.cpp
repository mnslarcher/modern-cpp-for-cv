struct SomeOtherClass {};

class MyClass {
 public:
  MyClass() { data_ = new SomeOtherClass; }
  ~MyClass() {
    delete data_;
    data_ = nullptr;
  }

 private:
  SomeOtherClass* data_;
};

int main() {
  MyClass a;
  MyClass b(a);
  return 0;
}