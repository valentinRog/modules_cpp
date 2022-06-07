#include "Span.hpp"
#include <cstdlib>
#include <iostream>

struct random_functor {
    int operator()() { return rand() % 10000; }
};

int main() {
    srand( time( 0 ) );

    {
        const unsigned int n  = 1 << 16;
        Span               sp = Span( n );

        std::vector<int> v( n );
        std::generate( v.begin(), v.end(), random_functor() );
        sp.addNumber( v.begin(), v.end() );
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    return 0;
}
