#include "Cure.hpp"

/* -------------------------------------------------------------------------- */

Cure::Cure() : AMateria( "cure" ) {
    std::cout << "[Cure] Default constructor called" << std::endl;
}

Cure::Cure( Cure const &other ) : AMateria( "cure" ) {
    *this = other;
    std::cout << "[Cure] Copy constructor called" << std::endl;
}

Cure &Cure::operator=( Cure const &other ) {
    AMateria::operator=( other );
    std::cout << "[Cure] Copy assignment operator called" << std::endl;
    return *this;
}

Cure::~Cure() { std::cout << "[Cure] Destructor called" << std::endl; }

/* -------------------------------------------------------------------------- */

AMateria *Cure::clone() const { return new Cure( *this ); }

void Cure::use( ICharacter &target ) {
    std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}

/* -------------------------------------------------------------------------- */
