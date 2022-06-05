#include "Data.hpp"
#include <iostream>

int main() {
    Data *    ptr = new Data;
    Data *    new_ptr;
    uintptr_t raw;

    ptr->n  = 42;
    raw     = serialize( ptr );
    new_ptr = deserialize( raw );
    std::cout << new_ptr->n << std::endl;

    delete ptr;

    return 0;
}
