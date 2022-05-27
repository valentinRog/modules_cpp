#include "Cat.hpp"

/* -------------------------------------------------------------------------- */

Cat::Cat() {
    _type = "Cat";
    std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat( Cat const &other ) : Animal() {
    std::cout << "[Cat] Copy constructor called" << std::endl;
    *this = other;
}

Cat &Cat::operator=( Cat const &other ) {
    _type = other._type;
    std::cout << "[Cat] Copy assignment operator called" << std::endl;

    return *this;
}

Cat::~Cat() { std::cout << "[Cat] Destructor called" << std::endl; }

/* -------------------------------------------------------------------------- */

void Cat::makeSound() const { std::cout << "[Cat] Meow..." << std::endl; }

/* -------------------------------------------------------------------------- */
