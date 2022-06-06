#include "Array.hpp"

/* -------------------------------------------------------------------------- */

template <typename T> std::out_of_range Array<T>::_outOfRange( "out of range" );

/* -------------------------------------------------------------------------- */

template <typename T> Array<T>::Array() : _arr( 0 ), _size( 0 ) {}

template <typename T> Array<T>::Array( unsigned int n ) : _size( n ) {
    _arr = new T[n];
    for ( unsigned int i = 0; i < n; i++ ) {
        T *tmp  = new T;
        _arr[i] = *tmp;
        delete tmp;
    }
}

template <typename T> Array<T>::Array( Array<T> const &other ) {
    *this = other;
}

template <typename T> Array<T> &Array<T>::operator=( Array<T> const &other ) {
    if ( _arr ) { delete _arr; }
    _size = other._size;
    if ( _size ) { _arr = new T[_size]; }
    for ( unsigned int i = 0; i < _size; i++ ) { _arr[i] = other._arr[i]; }
    return *this;
}

template <typename T> Array<T>::~Array() {
    if ( _arr ) { delete _arr; }
}

/* -------------------------------------------------------------------------- */

template <typename T> T &Array<T>::operator[]( unsigned int i ) {
    if ( i >= _size ) { throw _outOfRange; }
    return _arr[i];
}

/* -------------------------------------------------------------------------- */

template <typename T> unsigned int Array<T>::size() const { return _size; }

/* -------------------------------------------------------------------------- */

template <typename T>
std::ostream &operator<<( std::ostream &os, Array<T> &arr ) {
    os << "[ ";
    for ( unsigned int i = 0; i < arr.size(); i++ ) {
        if ( i ) { os << ", "; }
        os << arr[i];
    }
    os << " ]";
    return os;
}

/* -------------------------------------------------------------------------- */
