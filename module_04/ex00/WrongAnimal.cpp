#include "WrongAnimal.hpp"

/* -------------------------------------------------------------------------- */

WrongAnimal::WrongAnimal() {
    _type = "WrongAnimal";
    std::cout << "[WrongAnimal] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &other ) {
    std::cout << "[WrongAnimal] Copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=( WrongAnimal const &other ) {
    _type = other._type;
    std::cout << "[WrongAnimal] Copy assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

std::string const &WrongAnimal::getType() const { return _type; }

/* -------------------------------------------------------------------------- */

void WrongAnimal::makeSound() const {
    std::cout << "[WrongAnimal] * Generic animal sound... *" << std::endl;
}

/* -------------------------------------------------------------------------- */

void WrongAnimal::print( std::ostream &os ) const {
    os << "{ ";
    os << "type: "
       << "\"" << _type << "\"";
    os << " }";
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, WrongAnimal const &wrongAnimal ) {
    wrongAnimal.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
