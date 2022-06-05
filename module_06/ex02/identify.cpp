#include "identify.hpp"

Base *generate() {
    switch ( rand() % 3 ) {
    case 0:
        return new A;
    case 1:
        return new B;
    default:
        return new C;
    }
}
void identify( Base *p ) {
    if ( dynamic_cast<A *>( p ) ) {
        std::cout << "A";
    } else if ( dynamic_cast<B *>( p ) ) {
        std::cout << "B";
    } else if ( dynamic_cast<C *>( p ) ) {
        std::cout << "C";
    }
}

void identify( Base &p ) {
    try {
        dynamic_cast<A &>( p );
        std::cout << "A";
    } catch ( const std::exception &e ) { ( void ) e; }

    try {
        dynamic_cast<B &>( p );
        std::cout << "B";
    } catch ( const std::exception &e ) { ( void ) e; }

    try {
        dynamic_cast<C &>( p );
        std::cout << "C";
    } catch ( const std::exception &e ) { ( void ) e; }
}
