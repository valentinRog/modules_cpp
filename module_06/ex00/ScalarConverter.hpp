#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <climits>
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <typeinfo>

#include "ConvertUtils.tpp"

class ScalarConverter {

private:
    char *  _c;
    int *   _i;
    float * _f;
    double *_d;

    static std::runtime_error _conversionError;

    char   str_to_char( std::string const &str );
    int    str_to_int( std::string const &str );
    float  str_to_float( std::string const &str );
    double str_to_double( std::string const &str );

    void delete_values();

public:
    ScalarConverter();
    ScalarConverter( std::string const &str );
    ScalarConverter( ScalarConverter const &other );
    ScalarConverter &operator=( ScalarConverter const &other );
    ~ScalarConverter();

    void print( std::ostream &os ) const;
};

std::ostream &operator<<( std::ostream &os, ScalarConverter const &sc );

#endif
