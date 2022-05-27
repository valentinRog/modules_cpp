#include "AAnimal.hpp"

/* -------------------------------------------------------------------------- */

AAnimal::AAnimal() {
    _type = "AAnimal";
    std::cout << "[AAnimal] Default constructor called" << std::endl;
}

AAnimal::AAnimal( AAnimal const &other ) {
    std::cout << "[AAnimal] Copy constructor called" << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator=( AAnimal const &other ) {
    _type = other._type;
    std::cout << "[AAnimal] Copy assignment operator called" << std::endl;

    return *this;
}

AAnimal::~AAnimal() { std::cout << "[AAnimal] Destructor called" << std::endl; }

/* -------------------------------------------------------------------------- */

std::string const &AAnimal::getType() const { return _type; }

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, AAnimal const &aanimal ) {
    aanimal.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
