#include "easyfind.hpp"
#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <random>

struct F {

public:
    F() : _i( 0 ) {}
    int operator()() { return _i++; }

private:
    int _i;
};

int main( void ) {
    std::vector<int> vect( 100 );

    std::generate( vect.begin(), vect.end(), F() );
    std::vector<int>::const_iterator it = easyfind( vect, 95 );
    if ( it != vect.end() ) {
        std::cout << "vect[" << it - vect.begin() << "] = " << *it << std::endl;
    }

    return 0;
}
