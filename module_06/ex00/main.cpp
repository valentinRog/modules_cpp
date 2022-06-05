#include "ScalarConverter.hpp"

int main( int argc, char **argv ) {
    if ( argc == 2 ) {
        try {
            ScalarConverter sc( argv[1] );
            std::cout << sc << std::endl;
        } catch ( std::exception &e ) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
