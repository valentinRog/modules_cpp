#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Contact {

  private:
	std::string	  _firstName;
	std::string	  _lastName;
	std::string	  _nickName;
	std::string	  _phoneNumber;
	std::string	  _darkestSecret;
	static size_t _fieldWidth;

  public:
	Contact();
	Contact( std::string firstName,
			 std::string lastName,
			 std::string nickName,
			 std::string phoneNumber,
			 std::string darkestSecret );
	size_t get_field_width() const;
	void   print_width( std::string str );
	void   print( bool endl = true );
	void   print_full();
};

#endif
