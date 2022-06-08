#include "iter.hpp"
#include <cstdlib>
#include <iostream>

namespace utils {
static void rand( int &x ) { x = ::rand() % 100; }
}

template <typename T> void put( T &data ) { std::cout << data << std::endl; }

int main( void ) {
    int const n   = 10;
    int      *arr = new int[n];

    srand( time( 0 ) );

    iter( arr, n, utils::rand );
    iter( arr, n, put );

    delete[] arr;

    return 0;
}
