#include "Contact.hpp"

size_t Contact::_fieldWidth = 10;

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

size_t Contact::get_field_width() const { return _fieldWidth; }

void Contact::print_width( std::string str ) {
    std::string tmp( str );

    if ( tmp.size() > _fieldWidth ) str[_fieldWidth - 1] = '.';
    std::cout << std::setfill( ' ' ) << std::setw( _fieldWidth )
              << str.substr( 0, _fieldWidth );
}

void Contact::print( bool endl ) {
    print_width( _firstName );
    std::cout << "|";
    print_width( _lastName );
    std::cout << "|";
    print_width( _nickName );
    if ( endl ) std::cout << std::endl;
}

void Contact::print_full() {
    std::cout << "first name: " << _firstName << std::endl;
    std::cout << "last name: " << _lastName << std::endl;
    std::cout << "nickname: " << _nickName << std::endl;
    std::cout << "phone number: " << _phoneNumber << std::endl;
    std::cout << "darkest secret: " << _darkestSecret << std::endl;
}
