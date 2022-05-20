#include "Fixed.hpp"

/* -------------------------------------------------------------------------- */

const int Fixed::_fractionalBits = 8;

/* -------------------------------------------------------------------------- */

Fixed::Fixed() : _rawBits( 0 ) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed( const int n ) : _rawBits( n << _fractionalBits ) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n )
    : _rawBits( roundf( n * ( 1 << _fractionalBits ) ) ) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=( const Fixed &other ) {
    std::cout << "Copy assignment operator called" << std::endl;
    _rawBits = other._rawBits;
    return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/* -------------------------------------------------------------------------- */

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}

/* -------------------------------------------------------------------------- */

float Fixed::toFloat() const {
    return ( float ) _rawBits / ( 1 << _fractionalBits );
}

int Fixed::toInt() const { return _rawBits >> _fractionalBits; }

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, const Fixed &fixed ) {
    os << fixed.toFloat();
    return os;
}

/* -------------------------------------------------------------------------- */
