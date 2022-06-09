#include "Span.hpp"

/* -------------------------------------------------------------------------- */

std::overflow_error Span::_overflowException( "max length exceeded" );
std::length_error   Span::_lengthException( "length too small" );

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

void Span::print( std::ostream &os ) const {
    os << "[ ";
    for ( std::vector<int>::const_iterator it = _vect.begin();
          it != _vect.end();
          it++ ) {
        if ( it != _vect.begin() ) { os << ", "; }
        os << *it;
    }
    os << " ]";
}

/* -------------------------------------------------------------------------- */

void Span::addNumber( int n ) {
    if ( _vect.size() < _n ) {
        _vect.push_back( n );
    } else {
        throw _overflowException;
    }
}

void Span::addNumber( std::vector<int>::iterator begin,
                      std::vector<int>::iterator end ) {
    if ( end + _vect.size() > _n + begin ) { throw _overflowException; }
    _vect.insert( _vect.end(), begin, end );
}

/* -------------------------------------------------------------------------- */

int Span::shortestSpan() const {
    if ( _vect.size() < 2 ) { throw _lengthException; }
    std::vector<int> v( _vect );
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
    if ( _vect.size() < 2 ) { throw _lengthException; }
    int min = *std::min_element( _vect.begin(), _vect.end() );
    int max = *std::max_element( _vect.begin(), _vect.end() );
    return max - min;
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, Span const &span ) {
    span.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
