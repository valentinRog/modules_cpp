#include "Array.hpp"

/* -------------------------------------------------------------------------- */

template <typename T> Array<T>::Array() : _arr( 0 ), _n( 0 ) {}

template <typename T> Array<T>::Array( unsigned int n ) : _n( n ) {
    _arr = new T[n];
}

template <typename T> Array<T>::Array( Array const &other ) { *this = other; }

template <typename T> Array<T> &Array<T>::operator=( Array<T> const &other ) {
    if ( _arr ) { delete _arr; }
    _n = other._n;
    if ( _n ) { _arr = new T[_n]; }
    for ( unsigned int i = 0; i < _n; i++ ) { _arr[i] = other._arr[i]; }
}

template <typename T> Array<T>::~Array() {
    if ( _arr ) { delete _arr; }
}

/* -------------------------------------------------------------------------- */

template <typename T> T const &Array<T>::operator[]( unsigned int i ) const {
    return _arr[i];
}

/* -------------------------------------------------------------------------- */

template <typename T> unsigned int Array<T>::size() const { return _n; }

/* -------------------------------------------------------------------------- */
