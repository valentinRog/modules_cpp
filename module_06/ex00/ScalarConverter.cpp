#include "ScalarConverter.hpp"

/* -------------------------------------------------------------------------- */

ScalarConverter::ScalarConverter()
    : _c( NULL ),
      _i( NULL ),
      _f( NULL ),
      _d( NULL ) {}

ScalarConverter::ScalarConverter( std::string const &str )
    : _str( str ),
      _c( NULL ),
      _i( NULL ),
      _f( NULL ),
      _d( NULL ) {}

ScalarConverter::ScalarConverter( ScalarConverter const &other ) {
    *this = other;
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &other ) {
    ( void ) other;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    if ( _c ) { delete _c; }
    if ( _i ) { delete _i; }
    if ( _f ) { delete _f; }
    if ( _d ) { delete _d; }
}

/* -------------------------------------------------------------------------- */
