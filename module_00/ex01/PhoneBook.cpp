#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
  _insertIndex = 0;
  _contactCount = 0;
}

void PhoneBook::add_contact(Contact contact) {
  _contacts[_insertIndex] = Contact(contact);
  _insertIndex++;
  if (_insertIndex >= N_CONTACT) {
    _insertIndex = 0;
  } else if (_contactCount < N_CONTACT)
    _contactCount++;
}

void PhoneBook::print() {
  for (int i = 0; i < _contactCount; i++)
    _contacts[i].print();
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
  if (!_contactCount) {
    std::cout << "empty table" << std::endl;
    return;
  }

  std::cout << "index: ";
  while (std::getline(std::cin, line)) {
    std::stringstream ss(line);
    if (ss >> index && index >= 0 && index < _contactCount)
      break;
    std::cout << "invalid index, please try again: ";
  }
  _contacts[index].print_full();
}
