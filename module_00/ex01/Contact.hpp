#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Contact {

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;

    static size_t _fieldWidth;

public:
    Contact();
    Contact( std::string firstName,
             std::string lastName,
             std::string nickName,
             std::string phoneNumber,
             std::string darkestSecret );

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    size_t get_field_width() const;

    void   print_width( std::string str ) const;
    void   print_line() const;
};

std::ostream &operator<<( std::ostream &os, const Contact &point );

#endif
