#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <climits>
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <typeinfo>

class ScalarConverter {

private:
    char *  _c;
    int *   _i;
    float * _f;
    double *_d;

    enum e_type { CHAR, INT, FLOAT, DOUBLE };

    static std::runtime_error _conversionError;

    template <typename T>
    std::string const try_conversion_from_str( std::string const &str );
    e_type            parse_type( std::string const &str );

    template <typename T> T convert_from_str( std::string const &str );
    template <typename T1, typename T2> T2 *convert( T1 const n );
    template <typename T> void              fill_values( T n );

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
