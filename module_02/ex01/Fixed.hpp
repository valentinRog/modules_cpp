#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {

private:
    int _raw;

    static const int _fractionalBits;

public:
    Fixed();
    Fixed( const Fixed &other );
    Fixed( const int n );
    Fixed( const float n );
    Fixed &operator=( const Fixed &other );
    ~Fixed();

    int  getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat() const;
    int   toInt() const;
};

std::ostream &operator<<( std::ostream &os, const Fixed &fixed );

#endif