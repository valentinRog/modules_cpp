#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#define N_CONTACT 8

#include <iostream>
#include <sstream>

#include "Contact.hpp"

class PhoneBook {
private:
  Contact _contacts[N_CONTACT];
  int _insertIndex;
  int _contactCount;
  void add_contact(Contact contact);
  void print();

public:
  PhoneBook();
  void add();
  void search();
};

#endif
