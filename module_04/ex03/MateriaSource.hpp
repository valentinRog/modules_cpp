#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource {

private:
    static int const _nMaterias = 4;
    AMateria *       _materias[_nMaterias];

public:
    MateriaSource();
    MateriaSource( MateriaSource const &other );
    MateriaSource &operator=( MateriaSource const &other );
    ~MateriaSource( void );

    virtual void      learnMateria( AMateria *materia );
    virtual AMateria *createMateria( std::string const &type );

    void print( std::ostream &os ) const;
};

#endif
