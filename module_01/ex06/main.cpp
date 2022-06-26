#include <iostream>
#include <string>

#include "Harl.hpp"

int main( int argc, char **argv ) {
    if ( argc != 2 ) {
        std::cerr << "Error: 1 positional argument required" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complainFilter( argv[1] );
}
