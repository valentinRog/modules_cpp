#include "Contact.hpp"

/* -------------------------------------------------------------------------- */

size_t Contact::_fieldWidth = 10;

/* -------------------------------------------------------------------------- */

Contact::Contact() {}

Contact::Contact( std::string firstName,
                  std::string lastName,
                  std::string nickName,
                  std::string phoneNumber,
                  std::string darkestSecret )
    : _firstName( firstName ),
      _lastName( lastName ),
      _nickName( nickName ),
      _phoneNumber( phoneNumber ),
      _darkestSecret( darkestSecret ) {}

/* -------------------------------------------------------------------------- */

std::string Contact::getFirstName() const { return _firstName; }

std::string Contact::getLastName() const { return _lastName; }

std::string Contact::getNickName() const { return _nickName; }

std::string Contact::getPhoneNumber() const { return _phoneNumber; }

std::string Contact::getDarkestSecret() const { return _darkestSecret; }

/* -------------------------------------------------------------------------- */

size_t Contact::get_field_width() const { return _fieldWidth; }

/* -------------------------------------------------------------------------- */

void Contact::print_width( std::string str ) const {
    std::string tmp( str );

    if ( tmp.size() > _fieldWidth ) str[_fieldWidth - 1] = '.';
    std::cout << std::setfill( ' ' ) << std::setw( _fieldWidth )
              << str.substr( 0, _fieldWidth );
}

void Contact::print_line() const {
    print_width( _firstName );
    std::cout << "|";
    print_width( _lastName );
    std::cout << "|";
    print_width( _nickName );
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, const Contact &point ) {
    os << "first name: " << point.getFirstName() << std::endl;
    os << "last name: " << point.getLastName() << std::endl;
    os << "nickname: " << point.getLastName() << std::endl;
    os << "phone number: " << point.getPhoneNumber() << std::endl;
    os << "darkest secret: " << point.getDarkestSecret();

    return os;
}

/* -------------------------------------------------------------------------- */
