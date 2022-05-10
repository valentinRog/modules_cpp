#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Contact {

private:
  std::string _firstName;
  std::string _lastName;
  std::string _phoneNumber;
  std::string _darkestSecret;
  unsigned int _fieldWidth;

public:
  Contact();
  Contact(std::string firstName, std::string lastName, std::string phoneNumber,
          std::string darkestSecret);
  unsigned int get_field_width() const;
  void print_width(std::string str);
  void print(bool endl = true);
  void print_full();
};

#endif
