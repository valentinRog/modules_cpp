#include "identify.h"
#include <iostream>

int main() {
    srand( time( 0 ) );

    {
        for ( int i = 0; i < 10; i++ ) {
            Base *p = generate();
            identify( p );
            std::cout << " ";
            identify( *p );
            std::cout << std::endl;
            delete p;
        }
    }
    std::cout << std::endl;
    {
        Base *a = new A();
        identify( a );
        identify( *a );
        std::cout << " ";
        Base *b = new B();
        identify( b );
        identify( *b );
        std::cout << " ";
        Base *c = new C();
        identify( c );
        identify( *c );
        std::cout << std::endl;
        delete a;
        delete b;
        delete c;
    }

    return 0;
}
