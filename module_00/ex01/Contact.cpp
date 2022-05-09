#include "Contact.hpp"

Contact::Contact() { _columnWidth = 10; }

Contact::Contact(std::string firstName, std::string lastName,
                 std::string phoneNumber, std::string darkestSecret) {
  _firstName = firstName;
  _lastName = lastName;
  _phoneNumber = phoneNumber;
  _darkestSecret = darkestSecret;
  _columnWidth = 10;
}

void Contact::print() {
  std::cout << std::setw(_columnWidth) << _firstName << "|";
  std::cout << std::setw(_columnWidth) << _lastName << "|";
  std::cout << std::setw(_columnWidth) << _phoneNumber << "|";
  std::cout << std::setw(_columnWidth) << _darkestSecret << std::endl;
}
