#include <iostream>
#include <string>

class Student {
 public:
  Student(int id, std::string name) : id_{id}, name_{name} {}
  int id() const { return id_; }
  const std::string& name() const { return name_; }

 private:
  int id_;
  std::string name_;
};

int main() {
  Student student = Student(0, "Mario");
  std::cout << "The ID " << student.id() << " corresponds to " << student.name()
            << std::endl;
  return 0;
}