#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "Contact.hpp"

class PhoneBook {
private:
    static int const _contactMax = 8;

    Contact          _contacts[_contactMax];

    int              _insertIndex;
    int              _contactCount;

    void             add_contact( Contact contact );

public:
    PhoneBook();

    Contact *getContacts() const;
    int getContactCount() const;

    void add();
    void search();
};

std::ostream &operator<<( std::ostream &os, const PhoneBook &phoneBook );

#endif
