#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
  _insertIndex = 0;
  _contactCount = 0;
}

void PhoneBook::add_contact(Contact contact) {
  _contacts[_insertIndex] = Contact(contact);
  _insertIndex++;
  if (_insertIndex >= _contactMax) {
    _insertIndex = 0;
  } else if (_contactCount < _contactMax)
    _contactCount++;
}

void PhoneBook::print(char border) {
  if (!_contactCount) {
    std::cout << "Sadly, you don't have any friends..." << std::endl;
  }
  for (int i = 0; i < _contactCount; i++) {
    if (!i) {
      std::cout << std::string(_contacts[i].get_field_width() * 5 + 6, border)
                << std::endl;
      std::cout << border;
      _contacts[i].print_width("index");
      std::cout << "|";
      _contacts[i].print_width("first name");
      std::cout << "|";
      _contacts[i].print_width("last name");
      std::cout << "|";
      _contacts[i].print_width("phone number");
      std::cout << "|";
      _contacts[i].print_width("darkest secret");
      std::cout << border << std::endl;
      std::cout << std::string(_contacts[i].get_field_width() * 5 + 6, border)
                << std::endl;
    }
    std::stringstream ss;
    std::string str;
    ss << i;
    ss >> str;
    std::cout << border;
    _contacts[i].print_width(str);
    std::cout << "|";
    _contacts[i].print(false);
    std::cout << border << std::endl;
    if (i == _contactCount - 1) {
      std::cout << std::string(_contacts[i].get_field_width() * 5 + 6, border)
                << std::endl;
    }
  }
}

void PhoneBook::add() {
  std::string firstName;
  std::string lastName;
  std::string phoneNumber;
  std::string darkestSecret;

  std::cout << "first name: ";
  getline(std::cin, firstName);
  std::cout << "last name: ";
  getline(std::cin, lastName);
  std::cout << "phone number: ";
  getline(std::cin, phoneNumber);
  std::cout << "darkest secret: ";
  getline(std::cin, darkestSecret);
  add_contact(Contact(firstName, lastName, phoneNumber, darkestSecret));
}

void PhoneBook::search() {
  int index;
  std::string line;

  print();
  if (_contactCount) {
    std::cout << "index: ";
    while (std::getline(std::cin, line)) {
      std::stringstream ss(line);
      if (ss >> index && index >= 0 && index < _contactCount)
        break;
      std::cout << "invalid index, please try again: ";
    }
    _contacts[index].print_full();
  }
}
