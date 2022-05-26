#include "Animal.hpp"

/* -------------------------------------------------------------------------- */

Animal::Animal() {
    std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal( Animal const &other ) {
    std::cout << "[Animal] Copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=( Animal const &other ) {
    _type = other._type;
    std::cout << "[Animal] Copy assignment operator called" << std::endl;

    return *this;
}

Animal::~Animal() { std::cout << "[Animal] Destructor called" << std::endl; }

/* -------------------------------------------------------------------------- */

void Animal::makeSound() const {}

/* -------------------------------------------------------------------------- */
