#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter {

private:
    char   *_c;
    int    *_i;
    float  *_f;
    double *_d;

    static std::runtime_error _conversionError;

    template <typename T> static char   *convert_to_new_char( T n );
    template <typename T> static int    *convert_to_new_int( T n );
    template <typename T> static float  *convert_to_new_float( T n );
    template <typename T> static double *convert_to_new_double( T n );

    static char   str_to_char( std::string const &str );
    static int    str_to_int( std::string const &str );
    static float  str_to_float( std::string const &str );
    static double str_to_double( std::string const &str );

    template <typename T> void fill( T n );

    void delete_values();

public:
    ScalarConverter();
    ScalarConverter( std::string const &str );
    ScalarConverter( ScalarConverter const &other );
    ScalarConverter &operator=( ScalarConverter const &other );
    ~ScalarConverter();

    void print( std::ostream &os ) const;
};

#include "ScalarConverter.tpp"

std::ostream &operator<<( std::ostream &os, ScalarConverter const &sc );

#endif
