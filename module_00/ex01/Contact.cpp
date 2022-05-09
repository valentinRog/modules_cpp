#include "Contact.hpp"

Contact::Contact()
{
	
}

Contact::Contact(std::string firstName, std::string lastName,
                 std::string phoneNumber, std::string darkestSecret) {
  _firstName = firstName;
  _lastName = lastName;
  _phoneNumber = phoneNumber;
  _darkestSecret = darkestSecret;
}
