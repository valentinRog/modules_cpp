#include "Point.hpp"
#include <iostream>

static bool isleft( Point const a, Point const b, Point const p ) {
    float aX( a.getX().toFloat() );
    float aY( a.getY().toFloat() );
    float bX( b.getX().toFloat() );
    float bY( b.getY().toFloat() );
    float pX( p.getX().toFloat() );
    float pY( p.getY().toFloat() );

    return ( ( bX - aX ) * ( pY - aY ) - ( pX - aX ) * ( bY - aY ) ) > 0.0f;
}

bool bsp( Point const a, Point const b, Point const c, Point const p ) {
    return isleft( a, b, p ) && isleft( b, c, p ) && isleft( c, a, p );
}
