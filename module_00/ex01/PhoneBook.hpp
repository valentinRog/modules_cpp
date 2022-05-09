#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#define N_CONTACT 8

#include <iostream>

#include "Contact.hpp"

class PhoneBook {
private:
  Contact _contacts[N_CONTACT];
  int _insertIndex;
  int _contactCount;

public:
  PhoneBook();
  void add_contact(Contact contact);
  void print_contacts();
  void interactive_add();
  void interactive_search();
};

#endif
