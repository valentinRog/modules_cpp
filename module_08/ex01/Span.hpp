#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Span {

private:
    unsigned int     _n;
    std::vector<int> _v;

    static std::overflow_error _overflowException;
    static std::length_error   _lengthException;

public:
    Span();
    Span( unsigned int n );
    Span( Span const &other );
    Span &operator=( Span const &other );
    ~Span();

    void print( std::ostream &os ) const;

    void addNumber( int n );
    void addNumber( std::vector<int>::const_iterator begin,
                    std::vector<int>::const_iterator end );

    int shortestSpan() const;
    int longestSpan() const;
};

std::ostream &operator<<( std::ostream &os, Span const &span );

#endif
