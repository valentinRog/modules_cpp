#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {

private:
    int _rawBits;

    static int const _fractionalBits;

public:
    Fixed();
    Fixed( Fixed const &other );
    Fixed( int const n );
    Fixed( float const n );
    Fixed &operator=( Fixed const &other );
    ~Fixed();

    int  getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat() const;
    int   toInt() const;
};

std::ostream &operator<<( std::ostream &os, Fixed const &fixed );

#endif
