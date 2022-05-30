#include "ICharacter.hpp"

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, ICharacter const &iCharacter ) {
	iCharacter.print( os );
	return os;
}

/* -------------------------------------------------------------------------- */
