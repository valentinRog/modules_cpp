#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string firstName, std::string lastName,
                 std::string phoneNumber, std::string darkestSecret) {
  _firstName = firstName;
  _lastName = lastName;
  _phoneNumber = phoneNumber;
  _darkestSecret = darkestSecret;
}

void Contact::print_info() {
  std::cout << _firstName << "|";
  std::cout << _lastName << "|";
  std::cout << _phoneNumber << "|";
  std::cout << _darkestSecret << std::endl;
}
