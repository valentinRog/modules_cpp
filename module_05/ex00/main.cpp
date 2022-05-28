#include "Bureaucrat.hpp"
#include <iostream>

int main() {

    try {
        Bureaucrat b( "b", 120 );
        std::cout << b << std::endl;
        b.promote();
        std::cout << b << std::endl;
        b.demote();
        std::cout << b << std::endl;
    } catch ( std::exception const &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat b( "b", -9 );
        std::cout << b << std::endl;
        b.promote();
        std::cout << b << std::endl;
        b.demote();
        std::cout << b << std::endl;
    } catch ( std::exception const &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat b( "b", 160 );
        std::cout << b << std::endl;
        b.promote();
        std::cout << b << std::endl;
        b.demote();
        std::cout << b << std::endl;
    } catch ( std::exception const &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat b( "b", 1 );
        std::cout << b << std::endl;
        b.promote();
        std::cout << b << std::endl;
        b.demote();
        std::cout << b << std::endl;
    } catch ( std::exception const &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
