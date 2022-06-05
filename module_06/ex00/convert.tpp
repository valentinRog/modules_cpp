#include <limits>

template <typename T> char *convert_to_new_char( T n ) {
    if ( n >= std::numeric_limits<char>::min()
         && n <= std::numeric_limits<char>::max() ) {
        return new char( static_cast<char>( n ) );
    }
    return NULL;
}

template <typename T> int *convert_to_new_int( T n ) {
    if ( n >= std::numeric_limits<int>::min()
         && n <= std::numeric_limits<int>::max() ) {
        return new int( static_cast<int>( n ) );
    }
    return NULL;
}

template <typename T> float *convert_to_new_float( T n ) {
    if ( abs( n ) <= std::numeric_limits<float>::max() ) {
        return new float( static_cast<float>( n ) );
    }
    return NULL;
}

template <typename T> double *convert_to_new_double( T n ) {
    if ( abs( n ) <= std::numeric_limits<double>::max() ) {
        return new double( static_cast<double>( n ) );
    }
    return NULL;
}
