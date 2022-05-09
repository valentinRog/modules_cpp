#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#define N_CONTACT 8

#include "Contact.hpp"

class PhoneBook {
private:
  Contact _contacts[N_CONTACT];
  int     _contactCount;
public:
  PhoneBook();
};


#endif
