#include "Point.hpp"
#include <iostream>

int main( void ) {

    Point a( 0, 0 );
    Point b( 0, 4 );
    Point c( 4, 0 );
    Point p( 0.1f, 0.15f );

    std::cout << bsp( a, b, c, p ) << std::endl;

    return 0;
}
