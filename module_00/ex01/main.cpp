#include "PhoneBook.hpp"

int main() {
  std::string line;
  PhoneBook phoneBook;

  while (std::getline(std::cin, line)) {
    if (line == "ADD")
      phoneBook.add();
    else if (line == "SEARCH")
      phoneBook.search();
    else if (line == "EXIT")
      break;
    else
      std::cout << "invalid command" << std::endl;
  }
  return 0;
}
