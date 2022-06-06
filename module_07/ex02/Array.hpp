#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T> class Array {

private:
    T           *_arr;
    unsigned int _size;

    static std::out_of_range _outOfRange;

public:
    Array();
    Array( unsigned int n );
    Array( Array const &other );
    Array &operator=( Array<T> const &other );
    ~Array();

    T &operator[]( unsigned int i );

    unsigned int size() const;
};

template <typename T>
std::ostream &operator<<( std::ostream &os, Array<T> &arr );

#include "Array.tpp"

#endif
