#include "easyfind.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

struct F {
    int operator()() { return rand() % 10; }
};

static std::ostream &operator<<( std::ostream &os, std::vector<int> const &v ) {
    os << "[ ";
    for ( std::vector<int>::const_iterator it = v.begin(); it != v.end();
          it++ ) {
        if ( it != v.begin() ) { os << ", "; }
        os << *it;
    }
    os << " ]";
    return os;
}

int main() {
    srand( time( 0 ) );

    std::vector<int> v( 10 );
    std::generate( v.begin(), v.end(), F() );

    std::cout << v << std::endl;

    int const                        x  = 4;
    std::vector<int>::const_iterator it = easyfind( v, x );
    if ( it != v.end() ) {
        std::cout << x << ": Found at index " << it - v.begin() << std::endl;
    } else {
        std::cout << x << ": Not found" << std::endl;
    }

    return 0;
}
