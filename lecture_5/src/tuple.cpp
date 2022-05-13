#include <iostream>
#include <string>
#include <tuple>

using std::cout;
using std::endl;
using std::string;

void PrintStudent(std::tuple<double, char, string> student) {
  cout << "GPA " << std::get<0>(student) << ", grade: " << std::get<1>(student)
       << ", name: " << std::get<2>(student) << endl;
}

int main() {
  std::tuple<double, char, string> student1;
  using Student = std::tuple<double, char, string>;
  Student student2{1.4, 'A', "Jose"};
  PrintStudent(student2);
  cout << std::get<string>(student2) << endl;
  cout << std::get<2>(student2) << endl;
  auto [gpa, grade, name] = std::make_tuple(4.4, 'B', "");
}