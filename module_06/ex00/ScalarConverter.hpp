#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "convert.tpp"

class ScalarConverter {

private:
    char *  _c;
    int *   _i;
    float * _f;
    double *_d;

    static std::runtime_error _conversionError;

    char   str_to_char( std::string const &str ) const;
    int    str_to_int( std::string const &str ) const;
    float  str_to_float( std::string const &str ) const;
    double str_to_double( std::string const &str ) const;

    void fill( char n );
    void fill( int n );
    void fill( float n );
    void fill( double n );

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
