#include "ScalarConverter.hpp"

/* -------------------------------------------------------------------------- */

std::runtime_error ScalarConverter::_conversionError( "impossible conversion" );

/* -------------------------------------------------------------------------- */

ScalarConverter::ScalarConverter() { throw _conversionError; }

ScalarConverter::ScalarConverter( std::string const &str )
    : _c( 0 ),
      _i( 0 ),
      _f( 0 ),
      _d( 0 ) {
    try {
        _c = new char( str_to_char( str ) );
        fill( *_c );
    } catch ( std::exception & ) {
        try {
            _i = new int( str_to_int( str ) );
            fill( *_i );
        } catch ( std::exception & ) {
            try {
                _f = new float( str_to_float( str ) );
                fill( *_f );
            } catch ( std::exception & ) {
                _d = new double( str_to_double( str ) );
                fill( *_d );
            }
        }
    }
}

ScalarConverter::ScalarConverter( ScalarConverter const &other ) {
    *this = other;
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &other ) {
    delete_values();
    if ( other._c ) { _c = new char( *other._c ); }
    if ( other._i ) { _i = new int( *other._c ); }
    if ( other._f ) { _f = new float( *other._c ); }
    if ( other._d ) { _d = new double( *other._c ); }
    return *this;
}

ScalarConverter::~ScalarConverter() { delete_values(); }

/* -------------------------------------------------------------------------- */

void ScalarConverter::print( std::ostream &os ) const {
    os << std::fixed;
    os << "char: ";
    if ( _c ) {
        if ( std::isprint( *_c ) ) {
            os << "\'" << *_c << "\'";
        } else {
            os << "not printable";
        }
    } else {
        os << "impossible";
    }
    os << std::endl;
    os << "int: ";
    if ( _i ) {
        os << *_i;
    } else {
        os << "impossible";
    }
    os << std::endl;
    os << "float: ";
    if ( _f ) {
        os << *_f << "f";
    } else {
        os << "impossible";
    }
    os << std::endl;
    os << "double: ";
    if ( _d ) {
        os << *_d;
    } else {
        os << "impossible";
    }
}

/* -------------------------------------------------------------------------- */

char ScalarConverter::str_to_char( std::string const &str ) {
    if ( str.size() == 3 && str[0] == str[2] && str[0] == '\'' ) {
        return str[1];
    }
    throw _conversionError;
}

int ScalarConverter::str_to_int( std::string const &str ) {
    std::stringstream ss( str );
    int               n;
    std::string       buff;

    ss >> n;
    if ( ss.fail() || ss >> buff ) { throw _conversionError; }
    return n;
}

float ScalarConverter::str_to_float( std::string const &str ) {
    if ( str.back() != 'f' ) { throw _conversionError; }
    if ( str == "-inff" ) { return -std::numeric_limits<float>::infinity(); }
    if ( str == "+inff" ) { return std::numeric_limits<float>::infinity(); }
    if ( str == "nanf" ) { return std::numeric_limits<float>::quiet_NaN(); }
    if ( str.find( "." ) == std::string::npos ) { throw _conversionError; }
    std::stringstream ss( str.substr( 0, str.size() - 1 ) );
    float             n;
    std::string       buff;

    ss >> n;
    if ( ss.fail() || ss >> buff ) { throw _conversionError; }
    return n;
}

double ScalarConverter::str_to_double( std::string const &str ) {
    if ( str == "-inf" ) { return -std::numeric_limits<double>::infinity(); }
    if ( str == "+inf" ) { return std::numeric_limits<double>::infinity(); }
    if ( str == "nan" ) { return std::numeric_limits<double>::quiet_NaN(); }
    if ( str.find( "." ) == std::string::npos ) { throw _conversionError; }
    std::stringstream ss( str );
    double            n;
    std::string       buff;

    ss >> n;
    if ( ss.fail() || ss >> buff ) { throw _conversionError; }
    return n;
}

/* -------------------------------------------------------------------------- */

void ScalarConverter::delete_values() {
    if ( _c ) {
        delete _c;
        _c = 0;
    }
    if ( _i ) {
        delete _i;
        _i = 0;
    }
    if ( _f ) {
        delete _f;
        _f = 0;
    }
    if ( _d ) {
        delete _d;
        _d = 0;
    }
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, ScalarConverter const &sc ) {
    sc.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
