#include "Dog.hpp"

/* -------------------------------------------------------------------------- */

Dog::Dog() {
    _type = "Dog";
    std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog( Dog const &other ) : Animal( other ) {
    std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog &Dog::operator=( Dog const &other ) {
    Animal::operator=( other );
    std::cout << "[Dog] Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog() { std::cout << "[Dog] Destructor called" << std::endl; }

/* -------------------------------------------------------------------------- */

void Dog::makeSound() const { std::cout << "[Dog] Woaf !" << std::endl; }

/* -------------------------------------------------------------------------- */
