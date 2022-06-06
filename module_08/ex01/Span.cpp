#include "Span.hpp"

/* -------------------------------------------------------------------------- */

std::overflow_error Span::_overflowException( "overflow" );
std::length_error   Span::_lengthException( "length" );

/* -------------------------------------------------------------------------- */

Span::Span() : _n( 0 ) {}

Span::Span( unsigned int n ) : _n( n ) {}

Span::Span( Span const &other ) { *this = other; }

Span &Span::operator=( Span const &other ) {
    _n    = other._n;
    _vect = other._vect;
    return *this;
}

Span::~Span() {}

/* -------------------------------------------------------------------------- */

void Span::addNumber( int n ) {
    if ( _vect.size() < _n ) {
        _vect.push_back( n );
    } else {
        throw _overflowException;
    }
}

/* -------------------------------------------------------------------------- */

int Span::shortestSpan() {
    if ( _vect.size() < 2 ) { throw _lengthException; }
    std::vector<int> v( _vect );
    int              span = std::numeric_limits<int>::max();

    std::sort( v.begin(), v.end() );
    for ( std::vector<int>::iterator it = v.begin(); it + 1 != v.end(); it++ ) {
        if ( abs( *it - *( it + 1 ) ) < span ) {
            span = abs( *it - *( it + 1 ) );
        }
    }
    return span;
}

int Span::longestSpan() const {
    if ( _vect.size() < 2 ) { throw _lengthException; }
    int min = *std::min_element( _vect.begin(), _vect.end() );
    int max = *std::max_element( _vect.begin(), _vect.end() );
    return max - min;
}

/* -------------------------------------------------------------------------- */
