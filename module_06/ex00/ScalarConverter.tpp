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
    return 0;
}

template <typename T> int *ScalarConverter::convert_to_new_int( T n ) {
    if ( n >= std::numeric_limits<int>::min()
         && n <= std::numeric_limits<int>::max() ) {
        return new int( static_cast<int>( n ) );
    }
    return 0;
}

template <typename T> float *ScalarConverter::convert_to_new_float( T n ) {
    if ( isnan( n ) ) {
        return new float( std::numeric_limits<float>::quiet_NaN() );
    }
    if ( isinf( n ) ) {
        if ( n > 0 ) {
            return new float( std::numeric_limits<float>::infinity() );
        }
        return new float( -std::numeric_limits<float>::infinity() );
    }
    if ( abs( n ) <= std::numeric_limits<float>::max() ) {
        return new float( static_cast<float>( n ) );
    }
    return 0;
}

template <typename T> double *ScalarConverter::convert_to_new_double( T n ) {
    if ( isnan( n ) ) {
        return new double( std::numeric_limits<double>::quiet_NaN() );
    }
    if ( isinf( n ) ) {
        if ( n > 0 ) {
            return new double( std::numeric_limits<double>::infinity() );
        }
        return new double( -std::numeric_limits<double>::infinity() );
    }
    if ( abs( n ) <= std::numeric_limits<double>::max() ) {
        return new double( static_cast<double>( n ) );
    }
    return 0;
}

/* -------------------------------------------------------------------------- */
