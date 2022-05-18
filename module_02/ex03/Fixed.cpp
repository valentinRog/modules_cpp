#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _raw( 0 ) {}

Fixed::Fixed( const Fixed &other ) { *this = other; }

Fixed::Fixed( const int n ) : _raw( n << _fractionalBits ) {}

Fixed::Fixed( const float n )
    : _raw( roundf( n * ( 1 << _fractionalBits ) ) ) {}

Fixed &Fixed::operator=( const Fixed &other ) {
    _raw = other._raw;
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits( void ) const { return _raw; }

void Fixed::setRawBits( int const raw ) { _raw = raw; }

float Fixed::toFloat() const {
    return ( float ) _raw / ( 1 << _fractionalBits );
}

int Fixed::toInt() const { return _raw >> _fractionalBits; }

std::ostream &operator<<( std::ostream &os, const Fixed &fixed ) {
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>( const Fixed &other ) const { return _raw > other._raw; }

bool Fixed::operator<( const Fixed &other ) const { return _raw < other._raw; }

bool Fixed::operator>=( const Fixed &other ) const {
    return _raw >= other._raw;
}

bool Fixed::operator<=( const Fixed &other ) const {
    return _raw <= other._raw;
}

bool Fixed::operator==( const Fixed &other ) const {
    return _raw == other._raw;
}

bool Fixed::operator!=( const Fixed &other ) const {
    return _raw != other._raw;
}

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

Fixed Fixed::operator++() {
    _raw++;
    return *this;
}

Fixed Fixed::operator--() {
    _raw--;
    return *this;
}

Fixed Fixed::operator++( int ) { return ++Fixed( *this ); }

Fixed Fixed::operator--( int ) { return --Fixed( *this ); }

Fixed &Fixed::min( Fixed &a, Fixed &b ) { return b < a ? b : a; }

const Fixed &Fixed::min( const Fixed &a, const Fixed &b ) {
    return b < a ? b : a;
}

Fixed &Fixed::max( Fixed &a, Fixed &b ) { return b > a ? b : a; }

const Fixed &Fixed::max( const Fixed &a, const Fixed &b ) {
    return b > a ? b : a;
}
