#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {

private:
  std::string _firstName;
  std::string _lastName;
  std::string _phoneNumber;
  std::string _darkestSecret;

public:
  Contact();
  Contact(std::string fistName, std::string lastName, std::string phoneNumber,
          std::string darkestSecret);
};

#endif
