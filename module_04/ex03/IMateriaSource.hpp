#ifndef I_MATERIA_SOURCE_HPP
#define I_MATERIA_SOURCE_HPP

#include "AMateria.hpp"
#include <string>

class IMateriaSource {
public:
    virtual ~IMateriaSource(){};
    virtual void      learnMateria( AMateria      *)               = 0;
    virtual AMateria *createMateria( std::string const &type ) = 0;

    virtual void print( std::ostream &os ) const = 0;
};

std::ostream &operator<<( std::ostream         &os,
                          IMateriaSource const &iMateriaSource );

#endif
