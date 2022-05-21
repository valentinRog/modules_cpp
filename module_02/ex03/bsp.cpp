#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const p ) {

    Fixed aX( a.getX() );
    Fixed aY( a.getY() );
    Fixed bX( b.getX() );
    Fixed bY( b.getY() );
    Fixed cX( c.getX() );
    Fixed cY( c.getY() );
    Fixed pX( p.getX() );
    Fixed pY( p.getY() );

    Fixed s1 = cY - aY;
    Fixed s2 = cX - aX;
    Fixed s3 = bY - aY;
    Fixed s4 = pY - aY;

    Fixed w1 = ( aX * s1 + s4 * s2 - pX * s1 ) / ( s3 * s2 - ( bX - aX ) * s1 );
    Fixed w2 = ( s4 - w1 * s3 ) / s1;

    return w1 > 0 && w2 > 0 && ( w1 + w2 ) < 1;
}
