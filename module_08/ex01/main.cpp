#include "Span.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

struct randFunctor {
    int operator()() { return rand() % 1000; }
};

int main() {
    srand( time( 0 ) );

    {
        const unsigned int n  = 10;
        Span               sp = Span( n );

        std::vector<int> v( n );
        std::generate( v.begin(), v.end(), randFunctor() );
        sp.addNumber( v.begin(), v.end() );
        std::cout << sp << std::endl;
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
    std::cout << std::endl;
    {
        const unsigned int n  = 1 << 0xF;
        Span               sp = Span( n );

        std::vector<int> v( n );
        std::generate( v.begin(), v.end(), randFunctor() );
        sp.addNumber( v.begin(), v.end() );
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
    std::cout << std::endl;
    {
        Span sp;

        try {
            sp.addNumber( 8 );
        } catch ( std::exception &e ) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        try {
            sp.shortestSpan();
        } catch ( std::exception &e ) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    return 0;
}
