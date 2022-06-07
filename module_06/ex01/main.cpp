#include "Data.hpp"
#include <cstdlib>
#include <iostream>

int main() {
    Data     *new_ptr;
    uintptr_t raw;

    srand( time( NULL ) );
    for ( int i = 0; i < 5; i++ ) {
        if ( i ) { std::cout << std::endl; }
        Data *ptr = new Data;
        ptr->n    = rand() % 100;
        std::cout << ptr->n << std::endl;
        raw     = serialize( ptr );
        new_ptr = deserialize( raw );
        std::cout << new_ptr->n << std::endl;
        delete ptr;
    }

    return 0;
}
