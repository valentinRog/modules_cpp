#include "Data.hpp"

/* -------------------------------------------------------------------------- */

Data::Data() : _x( 0 ), _y( 0 ) {}

Data::Data( int const x, int const y ) : _x( x ), _y( y ) {}

Data::Data( Data const &other ) : _x( other._x ), _y( other._y ) {}

Data &Data::operator=( Data const &other ) {
    ( void ) other;
    return *this;
}

Data::~Data() {}

/* -------------------------------------------------------------------------- */
void Data::print( std::ostream &os ) const {
    os << "(" << _x << ", " << _y << ")";
}
/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, Data const &data ) {
    data.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
