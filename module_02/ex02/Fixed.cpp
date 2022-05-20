#include "Fixed.hpp"

/* -------------------------------------------------------------------------- */

const int Fixed::_fractionalBits = 8;

/* -------------------------------------------------------------------------- */

Fixed::Fixed() : _rawBits( 0 ) {}

Fixed::Fixed( const Fixed &other ) { *this = other; }

Fixed::Fixed( const int n ) : _rawBits( n << _fractionalBits ) {}

Fixed::Fixed( const float n )
    : _rawBits( roundf( n * ( 1 << _fractionalBits ) ) ) {}

Fixed &Fixed::operator=( const Fixed &other ) {
    _rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

/* -------------------------------------------------------------------------- */

int Fixed::getRawBits( void ) const { return _rawBits; }

void Fixed::setRawBits( int const raw ) { _rawBits = raw; }

/* -------------------------------------------------------------------------- */

float Fixed::toFloat() const {
    return ( float ) _rawBits / ( 1 << _fractionalBits );
}

int Fixed::toInt() const { return _rawBits >> _fractionalBits; }

/* -------------------------------------------------------------------------- */

bool Fixed::operator>( const Fixed &other ) const {
    return _rawBits > other.getRawBits();
}

bool Fixed::operator<( const Fixed &other ) const {
    return _rawBits < other.getRawBits();
}

bool Fixed::operator>=( const Fixed &other ) const {
    return _rawBits >= other.getRawBits();
}

bool Fixed::operator<=( const Fixed &other ) const {
    return _rawBits <= other.getRawBits();
}

bool Fixed::operator==( const Fixed &other ) const {
    return _rawBits == other.getRawBits();
}

bool Fixed::operator!=( const Fixed &other ) const {
    return _rawBits != other.getRawBits();
}

/* -------------------------------------------------------------------------- */

Fixed Fixed::operator+( const Fixed &other ) const {
    return Fixed( toFloat() + other.toFloat() );
}

Fixed Fixed::operator-( const Fixed &other ) const {
    return Fixed( toFloat() - other.toFloat() );
}

Fixed Fixed::operator*( const Fixed &other ) const {
    return Fixed( toFloat() * other.toFloat() );
}

Fixed Fixed::operator/( const Fixed &other ) const {
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
    Fixed swap( *this );
    _rawBits++;
    return swap;
}

Fixed Fixed::operator--( int ) {
    Fixed swap( *this );
    _rawBits--;
    return swap;
}

/* -------------------------------------------------------------------------- */

Fixed &Fixed::min( Fixed &a, Fixed &b ) { return b < a ? b : a; }

const Fixed &Fixed::min( const Fixed &a, const Fixed &b ) {
    return b < a ? b : a;
}

Fixed &Fixed::max( Fixed &a, Fixed &b ) { return b > a ? b : a; }

const Fixed &Fixed::max( const Fixed &a, const Fixed &b ) {
    return b > a ? b : a;
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, const Fixed &fixed ) {
    os << fixed.toFloat();
    return os;
}

/* -------------------------------------------------------------------------- */
