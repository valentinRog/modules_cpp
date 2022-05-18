#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const p ) {

    float aX( a.getX().toFloat() );
    float aY( a.getY().toFloat() );
    float bX( b.getX().toFloat() );
    float bY( b.getY().toFloat() );
    float cX( c.getX().toFloat() );
    float cY( c.getY().toFloat() );
    float pX( p.getX().toFloat() );
    float pY( p.getY().toFloat() );

    float s1 = cY - aY;
    float s2 = cX - aX;
    float s3 = bY - aY;
    float s4 = pY - aY;

    float w1 = ( aX * s1 + s4 * s2 - pX * s1 ) / ( s3 * s2 - ( bX - aX ) * s1 );
    float w2 = ( s4 - w1 * s3 ) / s1;

    return w1 > 0 && w2 > 0 && ( w1 + w2 ) < 1;
}
