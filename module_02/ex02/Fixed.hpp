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
    Fixed( const float n );
    Fixed &operator=( Fixed const &other );
    ~Fixed();

    int  getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat() const;
    int   toInt() const;

    bool operator>( Fixed const &other ) const;
    bool operator<( Fixed const &other ) const;
    bool operator>=( Fixed const &other ) const;
    bool operator<=( Fixed const &other ) const;
    bool operator==( Fixed const &other ) const;
    bool operator!=( Fixed const &other ) const;

    Fixed operator+( Fixed const &other ) const;
    Fixed operator-( Fixed const &other ) const;
    Fixed operator*( Fixed const &other ) const;
    Fixed operator/( Fixed const &other ) const;

    Fixed operator++();
    Fixed operator--();
    Fixed operator++( int );
    Fixed operator--( int );

    static Fixed &      min( Fixed &a, Fixed &b );
    static Fixed const &min( Fixed const &a, Fixed const &b );
    static Fixed &      max( Fixed &a, Fixed &b );
    static Fixed const &max( Fixed const &a, Fixed const &b );
};

std::ostream &operator<<( std::ostream &os, Fixed const &fixed );

#endif
