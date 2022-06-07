#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {

private:
    int const _x;
    int const _y;

public:
    Data();
    Data( int const x, int const y );
    Data( Data const &other );
    Data &operator=( Data const &other );
    ~Data();

    void print( std::ostream &os ) const;
};

std::ostream &operator<<( std::ostream &os, Data const &data );

#endif
