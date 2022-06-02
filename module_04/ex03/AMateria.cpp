#include "AMateria.hpp"

/* -------------------------------------------------------------------------- */

AMateria::AMateria() {
    std::cout << "[AMateria] Default constructor called" << std::endl;
}

AMateria::AMateria( std::string const &type ) : _type( type ) {
    std::cout << "[AMateria] Constructor called" << std::endl;
}

AMateria::AMateria( AMateria const &other ) {
    *this = other;
    std::cout << "[AMateria] Copy constructor called" << std::endl;
}

AMateria &AMateria::operator=( AMateria const &other ) {
    ( void ) other;
    std::cout << "[AMateria] Copy assignment operator called" << std::endl;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "[AMateria] Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

std::string const &AMateria::getType() const { return _type; }

/* -------------------------------------------------------------------------- */

void AMateria::use( ICharacter &target ) {
    ( void ) target;
    std::cout << "This function should be pure virtual..." << std::endl;
}

/* -------------------------------------------------------------------------- */

void AMateria::print( std::ostream &os ) const {
    os << "{ ";
    os << "type: "
       << "\"" << _type << "\"";
    os << " }";
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, AMateria const &materia ) {
    materia.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
