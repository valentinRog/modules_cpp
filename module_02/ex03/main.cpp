#include "Point.hpp"
#include <iostream>

int main( void ) {

    int const t = 5;

    Point arr[t][4]
        = { { Point( 0, 0 ), Point( 0, 0 ), Point( 0, 0 ), Point( 0, 0 ) },
            { Point( 0, 0 ), Point( 0, 0 ), Point( 0, 0 ), Point( 0, 0 ) },
            { Point( 0, 0 ), Point( 0, 0 ), Point( 0, 0 ), Point( 0, 0 ) },
            { Point( 0, 0 ), Point( 0, 0 ), Point( 0, 0 ), Point( 0, 0 ) },
            { Point( 0, 0 ), Point( 0, 0 ), Point( 0, 0 ), Point( 0, 0 ) } };

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
            std::cout << "p is in the triangle" << std::endl;
        } else {
            std::cout << "p is not in the triangle" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
