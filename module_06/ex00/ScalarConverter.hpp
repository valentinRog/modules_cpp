#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <typeinfo>
#include <cmath>
#include <climits>

class ScalarConverter {

private:
    char *  _c;
    int *   _i;
    float * _f;
    double *_d;

    enum e_type { CHAR, INT, FLOAT, DOUBLE };

    static std::runtime_error _conversionError;

    template <typename T>
    std::string const try_conversion( std::string const &str );
    e_type            parse_type( std::string const &str );

    template <typename T> T    convert( std::string const &str );
    template <typename T> void fill_values( T n );

	void delete_values();

public:
    ScalarConverter();
    ScalarConverter( std::string const &str );
    ScalarConverter( ScalarConverter const &other );
    ScalarConverter &operator=( ScalarConverter const &other );
    ~ScalarConverter();

	void print(std::ostream &os) const;
};

std::ostream &operator<<( std::ostream &os, ScalarConverter const &sc);

#endif
