#include "Array.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

static void fill( Array<int> &arr ) {
    for ( unsigned int i = 0; i < arr.size(); i++ ) { arr[i] = rand() % 1000; }
}

int main() {
    srand( time( 0 ) );

    {
        Array<int> *arr = new Array<int>( 20 );
        fill( *arr );
        std::cout << *arr << std::endl;
        Array<int> arrCopy( *arr );
        delete arr;
        std::cout << arrCopy << std::endl;
        std::cout << std::endl;
    }
    {
        Array<int> *arr = new Array<int>( 20 );
        fill( *arr );
        std::cout << *arr << std::endl;
        Array<int> arrCopy;
        arrCopy = *arr;
        delete arr;
        std::cout << arrCopy << std::endl;
        std::cout << std::endl;
    }

    {
        Array<Array<std::string> > chessBoard( 8 );
        for ( int i = 0; i < 8; i++ ) {
            Array<std::string> tmp( 8 );
            for ( int j = 0; j < 8; j++ ) {
                std::stringstream ss;
                ss << static_cast<char>( i + 'a' ) << j + 1;
                tmp[j] = ss.str();
            }
            chessBoard[i] = tmp;
        }
        std::cout << chessBoard << std::endl;
    }

    return 0;
}
