#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T> class Array {

private:
    T           *_arr;
    unsigned int _n;

public:
    Array();
    Array( unsigned int n );
    Array( Array const &other );
    Array &operator=( Array<T> const &other );
    ~Array();

    T const &operator[]( unsigned int i ) const;

    unsigned int size() const;
};

#include "Array.tpp"

#endif
