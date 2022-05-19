#include "Point.hpp"

Point::Point() : _x( Fixed( 0 ) ), _y( Fixed( 0 ) ) {}

Point::Point( float const x, float const y )
    : _x( Fixed( x ) ), _y( Fixed( y ) ) {}

Point::Point( const Point &other ) : _x( other.getX() ), _y( other.getY() ) {}

Point &Point::operator=( const Point &other ) {
    ( void ) other;
    return *this;
}

Point::~Point() {}

const Fixed &Point::getX() const { return _x; }

const Fixed &Point::getY() const { return _y; }

std::ostream &operator<<( std::ostream &os, const Point &point ) {
    os << "( " << point.getX().toFloat() << ", " << point.getY().toFloat()
       << " )";
    return os;
}