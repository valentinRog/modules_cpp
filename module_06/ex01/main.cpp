#include "Data.hpp"
#include "serialize.h"
#include <cstdlib>
#include <iostream>

int main() {
    srand( time( 0 ) );

    Data     *new_ptr;
    uintptr_t raw;

    for ( int i = 0; i < 5; i++ ) {
        if ( i ) { std::cout << std::endl; }
        Data *ptr = new Data(rand() % 100, rand() % 100);
        std::cout << *ptr << std::endl;
        raw     = serialize( ptr );
        new_ptr = deserialize( raw );
        std::cout << *new_ptr << std::endl;
        delete ptr;
    }

    return 0;
}
