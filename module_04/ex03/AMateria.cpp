#include "AMateria.hpp"

/* -------------------------------------------------------------------------- */

AMateria::AMateria() {}

AMateria::AMateria( std::string const &type ) : _type( type ) {}

AMateria::AMateria( AMateria const &other ) { *this = other; }

AMateria &AMateria::operator=( AMateria const &other ) {
    _type = other._type;
    return *this;
}

AMateria::~AMateria() {}

/* -------------------------------------------------------------------------- */

std::string const &AMateria::getType() const { return _type; }

/* -------------------------------------------------------------------------- */

void AMateria::use( ICharacter &target ) { ( void ) target; }

/* -------------------------------------------------------------------------- */
