#include "MutantStack.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

struct F {

public:
    F() : _i( 0 ) {}
    int operator()() { return _i++; }

private:
    int _i;
};

int main() {
    std::vector<int> v( 5 );
    std::generate( v.begin(), v.end(), F() );

    {
        MutantStack<int> mstack;

        for ( std::vector<int>::const_iterator it = v.begin(); it != v.end();
              it++ ) {
            mstack.push( *it );
        }
        for ( MutantStack<int>::const_iterator it = mstack.begin();
              it != mstack.end();
              it++ ) {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
        for ( MutantStack<int>::const_reverse_iterator it = mstack.rbegin();
              it != mstack.rend();
              it++ ) {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
        mstack.pop();
        mstack.pop();
        for ( MutantStack<int>::const_iterator it = mstack.begin();
              it != mstack.end();
              it++ ) {
            std::cout << *it << std::endl;
        }
    }
    std::cout << "-----------------------------------------" << std::endl;
    {
        std::list<int> mstack;

        for ( std::vector<int>::const_iterator it = v.begin(); it != v.end();
              it++ ) {
            mstack.push_back( *it );
        }
        for ( std::list<int>::const_iterator it = mstack.begin(); it != mstack.end();
              it++ ) {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
        for ( std::list<int>::const_reverse_iterator it = mstack.rbegin();
              it != mstack.rend();
              it++ ) {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
        mstack.pop_back();
        mstack.pop_back();
        for ( std::list<int>::const_iterator it = mstack.begin();
              it != mstack.end();
              it++ ) {
            std::cout << *it << std::endl;
        }
    }
    return 0;
}
