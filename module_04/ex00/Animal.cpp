#include "Animal.hpp"

/* -------------------------------------------------------------------------- */

Animal::Animal() {
    _type = "Animal";
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

std::string const &Animal::getType() const { return _type; }

/* -------------------------------------------------------------------------- */

void Animal::makeSound() const {}

/* -------------------------------------------------------------------------- */

void Animal::print(std::ostream &os) const {
    os << "[Animal] ";
    os << "{ ";
    os << "type: " << "\"" << _type << "\"";
    os << " }";
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, Animal const & animal) {
    animal.print(os);
    return os;
}

/* -------------------------------------------------------------------------- */
