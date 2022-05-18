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

    bool operator>( const Fixed &other ) const;
    bool operator<( const Fixed &other ) const;
    bool operator>=( const Fixed &other ) const;
    bool operator<=( const Fixed &other ) const;
    bool operator==( const Fixed &other ) const;
    bool operator!=( const Fixed &other ) const;

    Fixed operator+( const Fixed &other ) const;
    Fixed operator-( const Fixed &other ) const;
    Fixed operator*( const Fixed &other ) const;
    Fixed operator/( const Fixed &other ) const;

    Fixed operator++();
    Fixed operator--();
    Fixed operator++( int );
    Fixed operator--( int );

    static Fixed       &min( Fixed &a, Fixed &b );
    static const Fixed &min( const Fixed &a, const Fixed &b );
    static Fixed       &max( Fixed &a, Fixed &b );
    static const Fixed &max( const Fixed &a, const Fixed &b );
};

std::ostream &operator<<( std::ostream &os, const Fixed &fixed );

#endif
