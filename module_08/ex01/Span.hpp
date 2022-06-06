#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <limits>
#include <vector>

class Span {

private:
    unsigned int     _n;
    std::vector<int> _vect;

    static std::overflow_error _overflowException;
    static std::length_error   _lengthException;

public:
    Span();
    Span( unsigned int n );
    Span( Span const &other );
    Span &operator=( Span const &other );
    ~Span();

    void addNumber( int n );

    int shortestSpan();
    int longestSpan() const;
};

#endif
