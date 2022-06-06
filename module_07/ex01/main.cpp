#include "iter.hpp"
#include <cstdlib>
#include <iostream>

void rand100( int &x ) { x = rand() % 100; }

template <typename T> void put( T &data ) { std::cout << data << std::endl; }

int main( void ) {
    int const n   = 10;
    int *     arr = new int[n];

    srand( time( NULL ) );

    iter( arr, n, rand100 );
    iter( arr, n, put );

    delete[] arr;

    return 0;
}
