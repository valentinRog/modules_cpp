#include "ScalarConverter.hpp"

/* -------------------------------------------------------------------------- */

template <typename T> void ScalarConverter::fill( T n ) {
    if ( !_c ) { _c = convert_to_new_char<T>( n ); }
    if ( !_i ) { _i = convert_to_new_int<T>( n ); }
    if ( !_f ) { _f = convert_to_new_float<T>( n ); }
    if ( !_d ) { _d = convert_to_new_double<T>( n ); }
}

/* -------------------------------------------------------------------------- */

template <typename T> char *ScalarConverter::convert_to_new_char( T n ) {
    if ( n >= std::numeric_limits<char>::min()
         && n <= std::numeric_limits<char>::max() ) {
        return new char( static_cast<char>( n ) );
    }
    return NULL;
}

template <typename T> int *ScalarConverter::convert_to_new_int( T n ) {
    if ( n >= std::numeric_limits<int>::min()
         && n <= std::numeric_limits<int>::max() ) {
        return new int( static_cast<int>( n ) );
    }
    return NULL;
}

template <typename T> float *ScalarConverter::convert_to_new_float( T n ) {
    if ( abs( n ) <= std::numeric_limits<float>::max() ) {
        return new float( static_cast<float>( n ) );
    }
    return NULL;
}

template <typename T> double *ScalarConverter::convert_to_new_double( T n ) {
    if ( abs( n ) <= std::numeric_limits<double>::max() ) {
        return new double( static_cast<double>( n ) );
    }
    return NULL;
}

/* -------------------------------------------------------------------------- */
