#include <cstdlib>
#include <iostream>
#include <random>

int main() {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> dist(0, 99);
  int number = dist(generator);
  int guess;
  while (true) {
    std::cout << "Choose a number between 0 and 99: ";
    if (std::cin >> guess) {
      if (guess < 0 or guess > 99) {
        std::cerr << "[WARNING] : Number must be between 0 and 99" << std::endl;
      } else {
        if (guess > number) {
          std::cout << "The number is smaller" << std::endl;
        } else if (guess < number) {
          std::cout << "The number is larger" << std::endl;
        } else {
          std::cout << "You have won!" << std::endl;
          std::cout << "The number to be guessed was " << number << std::endl;
          return EXIT_SUCCESS;
        }
      }
    } else {
      std::cout << "Error encountered, exiting..." << std::endl;
      std::cout << "The number to be guessed was " << number << std::endl;
      return EXIT_FAILURE;
    }
  }
}
