#include "Fixed.hpp"

/* -------------------------------------------------------------------------- */

int const Fixed::_fractionalBits = 8;

/* -------------------------------------------------------------------------- */

Fixed::Fixed() : _rawBits( 0 ) {}

Fixed::Fixed( Fixed const &other ) : _rawBits( other._rawBits ) {}

Fixed::Fixed( int const n ) : _rawBits( n << _fractionalBits ) {}

Fixed::Fixed( float const n )
    : _rawBits( roundf( n * ( 1 << _fractionalBits ) ) ) {}

Fixed &Fixed::operator=( Fixed const &other ) {
    _rawBits = other._rawBits;
    return *this;
}

Fixed::~Fixed() {}

/* -------------------------------------------------------------------------- */

int Fixed::getRawBits() const { return _rawBits; }

void Fixed::setRawBits( int const raw ) { _rawBits = raw; }

/* -------------------------------------------------------------------------- */

float Fixed::toFloat() const {
    return ( float ) _rawBits / ( 1 << _fractionalBits );
}

int Fixed::toInt() const { return _rawBits >> _fractionalBits; }

/* -------------------------------------------------------------------------- */

bool Fixed::operator>( Fixed const &other ) const {
    return _rawBits > other._rawBits;
}

bool Fixed::operator<( Fixed const &other ) const {
    return _rawBits < other._rawBits;
}

bool Fixed::operator>=( Fixed const &other ) const {
    return _rawBits >= other._rawBits;
}

bool Fixed::operator<=( Fixed const &other ) const {
    return _rawBits <= other._rawBits;
}

bool Fixed::operator==( Fixed const &other ) const {
    return _rawBits == other._rawBits;
}

bool Fixed::operator!=( Fixed const &other ) const {
    return _rawBits != other._rawBits;
}

/* -------------------------------------------------------------------------- */

Fixed Fixed::operator+( Fixed const &other ) const {
    return Fixed( toFloat() + other.toFloat() );
}

Fixed Fixed::operator-( Fixed const &other ) const {
    return Fixed( toFloat() - other.toFloat() );
}

Fixed Fixed::operator*( Fixed const &other ) const {
    return Fixed( toFloat() * other.toFloat() );
}

Fixed Fixed::operator/( Fixed const &other ) const {
    return Fixed( toFloat() / other.toFloat() );
}

/* -------------------------------------------------------------------------- */

Fixed Fixed::operator++() {
    _rawBits++;
    return *this;
}

Fixed Fixed::operator--() {
    _rawBits--;
    return *this;
}

Fixed Fixed::operator++( int ) {
    Fixed copy( *this );
    _rawBits++;
    return copy;
}

Fixed Fixed::operator--( int ) {
    Fixed copy( *this );
    _rawBits--;
    return copy;
}

/* -------------------------------------------------------------------------- */

Fixed &Fixed::min( Fixed &a, Fixed &b ) { return b < a ? b : a; }

Fixed const &Fixed::min( Fixed const &a, Fixed const &b ) {
    return b < a ? b : a;
}

Fixed &Fixed::max( Fixed &a, Fixed &b ) { return b > a ? b : a; }

Fixed const &Fixed::max( Fixed const &a, Fixed const &b ) {
    return b > a ? b : a;
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, Fixed const &fixed ) {
    os << fixed.toFloat();
    return os;
}

/* -------------------------------------------------------------------------- */
