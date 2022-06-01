#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>

class ScalarConverter {

private:
	std::string const _str;

	char *_c;
	int * _i;
	float * _f;
	double * _d;

public:
	ScalarConverter();
	ScalarConverter(std::string const &str);
	ScalarConverter(ScalarConverter const &other);
	ScalarConverter &operator=(ScalarConverter const &other);
	~ScalarConverter();

};

#endif
