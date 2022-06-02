#include "IMateriaSource.hpp"

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &        os,
                          IMateriaSource const &iMateriaSource ) {
    iMateriaSource.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
