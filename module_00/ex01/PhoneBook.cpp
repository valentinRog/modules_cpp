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

void PhoneBook::print_contacts() {
  for (int i = 0; i < _contactCount; i++)
    _contacts[i].print();
}
