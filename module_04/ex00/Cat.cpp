#include "Cat.hpp"

/* -------------------------------------------------------------------------- */

Cat::Cat() {
    _type = "Cat";
    std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat( Cat const &other ) : Animal( other ) {
    std::cout << "[Cat] Copy constructor called" << std::endl;
}

Cat &Cat::operator=( Cat const &other ) {
    Animal::operator=( other );
    std::cout << "[Cat] Copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat() { std::cout << "[Cat] Destructor called" << std::endl; }

/* -------------------------------------------------------------------------- */

void Cat::makeSound() const { std::cout << "[Cat] Meow..." << std::endl; }

/* -------------------------------------------------------------------------- */
