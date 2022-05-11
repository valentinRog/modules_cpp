#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include <string>
#include <sstream>

#include "Contact.hpp"

class PhoneBook {
private:
  static const int _contactMax = 8;
  Contact _contacts[_contactMax];
  int _insertIndex;
  int _contactCount;
  void add_contact(Contact contact);
  void print(char border = '*');

public:
  PhoneBook();
  void add();
  void search();
};

#endif
