#include "Ice.hpp"

/* -------------------------------------------------------------------------- */

Ice::Ice() : AMateria( "ice" ) {
    std::cout << "[Ice] Default constructor called" << std::endl;
}

Ice::Ice( Ice const &other ) : AMateria( "ice" ) {
    *this = other;
    std::cout << "[Ice] Copy constructor called" << std::endl;
}

Ice &Ice::operator=( Ice const &other ) {
    AMateria::operator=( other );
    std::cout << "[Ice] Copy assignment operator called" << std::endl;
    return *this;
}

Ice::~Ice() { std::cout << "[Ice] Destructor called" << std::endl; }

/* -------------------------------------------------------------------------- */

AMateria *Ice::clone() const { return new Ice( *this ); }

void Ice::use( ICharacter &target ) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}

/* -------------------------------------------------------------------------- */
