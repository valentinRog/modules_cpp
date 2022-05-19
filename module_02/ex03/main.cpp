#include "Point.hpp"
#include <iostream>

int main( void ) {

    typedef Point P;

    int const t = 5;

    Point arr[t][4]
        = { { P( 0, 0 ), P( 0, 0 ), P( 0, 0 ), P( 0, 0 ) },
            { P( 0.5f, 9 ), P( -8, 0 ), P( 0, -4 ), P( 0.1, -1 ) },
            { P( 0, 0 ), P( 7, 0 ), P( 0, 9 ), P( 0, 6 ) },
            { P( 0, 0 ), P( 5, 0 ), P( 0, 3.5f ), P( 1, 3.6f ) },
            { P( 0, 0 ), P( -8, 0 ), P( 0, 12.4f ), P( -1.2f, 0.8f ) } };

    std::cout << std::endl;

    for ( int i = 0; i < t; i++ ) {

        Point &a( arr[i][0] );
        Point &b( arr[i][1] );
        Point &c( arr[i][2] );
        Point &p( arr[i][3] );

        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "c = " << c << std::endl;
        std::cout << "p = " << p << std::endl;

        if ( bsp( a, b, c, p ) ) {
            std::cout << "p is in triangle abc" << std::endl;
        } else {
            std::cout << "p is not in triangle abc" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
