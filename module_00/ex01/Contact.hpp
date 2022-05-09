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
  unsigned int _columnWidth;
  void print_width(std::string str);

public:
  Contact();
  Contact(std::string firstName, std::string lastName, std::string phoneNumber,
          std::string darkestSecret);
  void print();
  void print_full();
};

#endif
