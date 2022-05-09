#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact {

private:
  std::string _firstName;
  std::string _lastName;
  std::string _phoneNumber;
  std::string _darkestSecret;
  unsigned int _columnWidth;

public:
  Contact();
  Contact(std::string fistName, std::string lastName, std::string phoneNumber,
          std::string darkestSecret);
  void print();
};

#endif
