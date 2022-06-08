#include "PhoneBook.hpp"

/* -------------------------------------------------------------------------- */

PhoneBook::PhoneBook() {
    _insertIndex  = 0;
    _contactCount = 0;
}

/* -------------------------------------------------------------------------- */

void PhoneBook::addContact( Contact contact ) {
    _contacts[_insertIndex] = contact;
    _insertIndex++;
    if ( _insertIndex >= _contactMax ) { _insertIndex = 0; }
    if ( _contactCount < _contactMax ) { _contactCount++; }
}

/* -------------------------------------------------------------------------- */

Contact *PhoneBook::getContacts() const { return ( Contact * ) _contacts; }

int PhoneBook::getContactCount() const { return _contactCount; }

/* -------------------------------------------------------------------------- */

void PhoneBook::add() {
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << "first name: ";
    getline( std::cin, firstName );
    std::cout << "last name: ";
    getline( std::cin, lastName );
    std::cout << "nickname: ";
    getline( std::cin, nickName );
    std::cout << "phone number: ";
    getline( std::cin, phoneNumber );
    std::cout << "darkest secret: ";
    getline( std::cin, darkestSecret );
    addContact(
        Contact( firstName, lastName, nickName, phoneNumber, darkestSecret ) );
}

void PhoneBook::search() {
    int         index;
    std::string line;

    std::cout << *this << std::endl;
    if ( _contactCount ) {
        std::cout << "index: ";
        while ( std::getline( std::cin, line ) ) {
            std::stringstream ss( line );
            if ( ss >> index && index >= 0 && index < _contactCount ) break;
            std::cout << "invalid index, please try again: ";
        }
        std::cout << _contacts[index] << std::endl;
    }
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, const PhoneBook &phoneBook ) {
    if ( !phoneBook.getContactCount() ) {
        std::cout << "Sadly, you don't have any friends..." << std::endl;
    }

    char border( '*' );

    for ( int i = 0; i < phoneBook.getContactCount(); i++ ) {
        size_t headerWidth
            = phoneBook.getContacts()[i].get_field_width() * 4 + 5;
        if ( !i ) {
            std::cout << std::string( headerWidth, border ) << std::endl;
            std::cout << border;
            phoneBook.getContacts()[i].print_width( "index" );
            std::cout << "|";
            phoneBook.getContacts()[i].print_width( "first name" );
            std::cout << "|";
            phoneBook.getContacts()[i].print_width( "last name" );
            std::cout << "|";
            phoneBook.getContacts()[i].print_width( "nickname" );
            std::cout << border << std::endl;
            std::cout << std::string( headerWidth, border ) << std::endl;
        }
        std::stringstream ss;
        std::string       str;
        ss << i;
        ss >> str;
        std::cout << border;
        phoneBook.getContacts()[i].print_width( str );
        std::cout << "|";
        phoneBook.getContacts()[i].print_line();
        std::cout << border << std::endl;
        if ( i == phoneBook.getContactCount() - 1 ) {
            std::cout << std::string( headerWidth, border ) << std::endl;
        }
    }
    return os;
}

/* -------------------------------------------------------------------------- */
