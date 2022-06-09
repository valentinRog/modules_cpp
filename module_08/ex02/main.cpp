#include "MutantStack.hpp"
#include <iostream>
#include <algorithm>
#include <array>
#include <list>

struct uniqueFunctor {

public:
    uniqueFunctor() : _i( 0 ) {}
    int operator()() { return _i++; }

private:
    int _i;
};

int main() {
    std::array <int , 5> arr;
    std::generate(arr.begin(), arr.end(), uniqueFunctor());

    {
        MutantStack<int> mstack;

        for (std::array<int, 5>::iterator it = arr.begin(); it != arr.end(); it++) {
            mstack.push(*it);
        }
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
        for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++) {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
        mstack.pop();
        mstack.pop();
        for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); it++) {
            std::cout << *it << std::endl;
        }
    }
    std::cout << "-----------------------------------------" << std::endl;
    {
        std::list<int> mstack;

        for (std::array<int, 5>::iterator it = arr.begin(); it != arr.end(); it++) {
            mstack.push_back(*it);
        }
        for (std::list<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
        for (std::list<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++) {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
        mstack.pop_back();
        mstack.pop_back();
        for (std::list<int>::const_iterator it = mstack.begin(); it != mstack.end(); it++) {
            std::cout << *it << std::endl;
        }
    }
    return 0;
}
