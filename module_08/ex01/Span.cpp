#include "Span.hpp"

/* -------------------------------------------------------------------------- */

std::overflow_error Span::_overflowException( "max length exceeded" );
std::length_error   Span::_lengthException( "length too small" );

/* -------------------------------------------------------------------------- */

Span::Span() : _n( 0 ) {}

Span::Span( unsigned int n ) : _n( n ) {}

Span::Span( Span const &other ) { *this = other; }

Span &Span::operator=( Span const &other ) {
    _n = other._n;
    _v = other._v;
    return *this;
}

Span::~Span() {}

/* -------------------------------------------------------------------------- */

void Span::print( std::ostream &os ) const {
    os << "[ ";
    for ( std::vector<int>::const_iterator it = _v.begin(); it != _v.end();
          it++ ) {
        if ( it != _v.begin() ) { os << ", "; }
        os << *it;
    }
    os << " ]";
}

/* -------------------------------------------------------------------------- */

void Span::addNumber( int n ) {
    if ( _v.size() < _n ) {
        _v.push_back( n );
    } else {
        throw _overflowException;
    }
}

void Span::addNumber( std::vector<int>::const_iterator begin,
                      std::vector<int>::const_iterator end ) {
    if ( end + _v.size() > _n + begin ) { throw _overflowException; }
    _v.insert( _v.end(), begin, end );
}

/* -------------------------------------------------------------------------- */

int Span::shortestSpan() const {
    if ( _v.size() < 2 ) { throw _lengthException; }
    std::vector<int> v( _v );
    int              span = std::numeric_limits<int>::max();

    std::sort( v.begin(), v.end() );
    for ( std::vector<int>::const_iterator it = v.begin(); it + 1 != v.end();
          it++ ) {
        if ( abs( *it - *( it + 1 ) ) < span ) {
            span = abs( *it - *( it + 1 ) );
        }
    }
    return span;
}

int Span::longestSpan() const {
    if ( _v.size() < 2 ) { throw _lengthException; }
    int min = *std::min_element( _v.begin(), _v.end() );
    int max = *std::max_element( _v.begin(), _v.end() );
    return max - min;
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, Span const &span ) {
    span.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
