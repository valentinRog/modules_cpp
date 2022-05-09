#include "PhoneBook.hpp"

int main() {
  std::string line;
  PhoneBook phoneBook;

  while (std::getline(std::cin, line)) {
    std::cout << line << std::endl;
  }
  return 0;
}
