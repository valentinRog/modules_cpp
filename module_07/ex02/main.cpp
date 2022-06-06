#include "Array.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

static void fill_rand1000( Array<int> &arr ) {
    for ( unsigned int i = 0; i < arr.size(); i++ ) { arr[i] = rand() % 1000; }
}

int main() {
    srand( time( NULL ) );

    {
        Array<int> *arr = new Array<int>( 20 );
        fill_rand1000( *arr );
        std::cout << *arr << std::endl;
        Array<int> arrCopy( *arr );
        delete arr;
        std::cout << arrCopy << std::endl;
        std::cout << std::endl;
    }
    {
        Array<int> *arr = new Array<int>( 20 );
        fill_rand1000( *arr );
        std::cout << *arr << std::endl;
        Array<int> arrCopy;
        arrCopy = *arr;
        delete arr;
        std::cout << arrCopy << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
