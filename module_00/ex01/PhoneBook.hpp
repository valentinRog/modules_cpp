#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "Contact.hpp"

class PhoneBook {
private:
    static const int _contactMax = 8;

    Contact          _contacts[_contactMax];

    int              _insertIndex;
    int              _contactCount;

    void             add_contact( Contact contact );
    void             print_line( char border = '*' );

public:
    PhoneBook();

    Contact *getContacts() const {return (Contact*)_contacts;}
    int getContactCount() const { return _contactCount;}

    void add();
    void search();
};

std::ostream &operator<<( std::ostream &os, const PhoneBook &phoneBook );

#endif
