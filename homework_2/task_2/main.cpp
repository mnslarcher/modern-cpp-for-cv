#include <cstdlib>
#include <iostream>
#include <sstream>

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    std::cerr << "Expected 2 arguments, got " << argc - 1 << std::endl;
    return EXIT_FAILURE; // same as 1
  }

  std::stringstream filename1{argv[1]}, filename2{argv[2]};
  int num1, num2;
  std::string ext1, ext2;

  filename1 >> num1 >> ext1;
  filename2 >> num2 >> ext2;

  if (ext1 == ".txt" and ext2 == ".txt") {
    std::cout << (num1 + num2) / 2 << std::endl;
  } else if (ext1 == ".png" and ext2 == ".png") {
    std::cout << num1 + num2 << std::endl;
  } else if (ext1 == ".txt" and ext2 == ".png") {
    std::cout << num1 % num2 << std::endl;
  } else {
    std::cerr << "Expected .txt/.txt, .png/.png or .txt/.png, got " << ext1
              << "/" << ext2 << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS; // same as 0
}