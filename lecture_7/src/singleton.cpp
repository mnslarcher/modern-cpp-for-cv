class Singleton {
 public:
  Singleton(const Singleton&) = delete;  // Copy Constructor, MyClass a = b;
  void operator=(const Singleton&) =
      delete;  // Copy Assigment Operator, a = b (a already exits);

  static Singleton& GetInstance() {
    static Singleton instance;  // The class can use the private constructor...
    return instance;
  }

 private:
  Singleton() = default;
  ~Singleton() = default;
};

int main() {
  auto& singleton = Singleton::GetInstance();
  return 0;
}