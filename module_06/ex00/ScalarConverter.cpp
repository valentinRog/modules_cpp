#include "ScalarConverter.hpp"

/* -------------------------------------------------------------------------- */

std::runtime_error ScalarConverter::_conversionError( "impossible conversion" );

/* -------------------------------------------------------------------------- */

ScalarConverter::ScalarConverter()
    : _c( NULL ),
      _i( NULL ),
      _f( NULL ),
      _d( NULL ) {
    throw _conversionError;
}

ScalarConverter::ScalarConverter( std::string const &str )
    : _c( NULL ),
      _i( NULL ),
      _f( NULL ),
      _d( NULL ) {
    switch ( parse_type( str ) ) {
    case CHAR:
        fill_values<char>( str[1] );
        break;
    case INT:
        fill_values<int>( convert_from_str<int>( str ) );
        break;
    case FLOAT:
        fill_values<float>( convert_from_str<float>( str ) );
        break;
    case DOUBLE:
        fill_values<double>( convert_from_str<double>( str ) );
        break;
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

template <typename T>
std::string const
ScalarConverter::try_conversion_from_str( std::string const &str ) {
    std::stringstream ss( str );
    T                 n;
    std::string       remainStr;

    ss >> n;
    if ( ss.fail() ) { throw _conversionError; }
    ss >> remainStr;
    return remainStr;
}

ScalarConverter::e_type ScalarConverter::parse_type( std::string const &str ) {
    if ( str == "-inff" || str == "+inff" || str == "nanf" ) { return FLOAT; }
    if ( str == "-inf" || str == "+inf" || str == "nan" ) { return DOUBLE; }
    if ( str.size() == 3 && *str.begin() == *str.rbegin()
         && *str.begin() == '\'' ) {
        return CHAR;
    }
    if ( str.find( '.' ) != std::string::npos ) {
        if ( try_conversion_from_str<double>( str ).empty() ) { return DOUBLE; }

        if ( try_conversion_from_str<float>( str ).size() == 1
             && *try_conversion_from_str<float>( str ).begin() == 'f' ) {
            return FLOAT;
        }
    }
    if ( try_conversion_from_str<int>( str ).empty() ) { return INT; }
    throw _conversionError;
}

/* -------------------------------------------------------------------------- */

template <typename T>
T ScalarConverter::convert_from_str( std::string const &str ) {
    if ( str == "-inff" || str == "-inf" ) {
        return -std::numeric_limits<T>::infinity();
    }
    if ( str == "+inff" || str == "+inf" ) {
        return std::numeric_limits<T>::infinity();
    }
    if ( str == "nanf" || str == "nan" ) {
        return std::numeric_limits<T>::quiet_NaN();
    }

    std::stringstream ss( str );
    T                 n;
    ss >> n;
    return n;
}

template <typename T1, typename T2> T2 *ScalarConverter::convert( T1 const n ) {
    if ( typeid( T2 ) == typeid( char ) || typeid( T2 ) == typeid( int ) ) {
        if ( n >= std::numeric_limits<T2>::min()
             && n <= std::numeric_limits<T2>::max() ) {
            return new T2( static_cast<T2>( n ) );
        }
    } else {
        if ( abs( n ) <= std::numeric_limits<T2>::max() ) {
            return new T2( static_cast<T2>( n ) );
        }
    }
    return NULL;
}

template <typename T> void ScalarConverter::fill_values( T n ) {
    _c = convert<T, char>( n );
    _i = convert<T, int>( n );
    _f = convert<T, float>( n );
    _d = convert<T, double>( n );
}

/* -------------------------------------------------------------------------- */

void ScalarConverter::delete_values() {
    if ( _c ) {
        delete _c;
        _c = NULL;
    }
    if ( _i ) {
        delete _i;
        _i = NULL;
    }
    if ( _f ) {
        delete _f;
        _f = NULL;
    }
    if ( _d ) {
        delete _d;
        _d = NULL;
    }
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, ScalarConverter const &sc ) {
    sc.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
