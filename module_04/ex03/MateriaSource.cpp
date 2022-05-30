#include "MateriaSource.hpp"

/* -------------------------------------------------------------------------- */

MateriaSource::MateriaSource() {
    for ( int i = 0; i < _nMaterias; i++ ) {
        _materias[i] = NULL;
        std::cout << "[MateriaSource] Default constructor called" << std::endl;
    }
}

MateriaSource::MateriaSource( MateriaSource const &other ) {
    *this = other;
    std::cout << "[MateriaSource] Copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=( MateriaSource const &other ) {
    for ( int i = 0; i < _nMaterias; i++ ) {
        if ( _materias[i] ) { delete _materias[i]; }
        if ( other._materias[i] ) {
            _materias[i] = other._materias[i]->clone();
        } else {
            _materias[i] = NULL;
        }
    }
    std::cout << "[MateriaSource] Copy assignment operator called" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource() {
    for ( int i = 0; i < _nMaterias; i++ ) {
        if ( _materias[i] ) { delete _materias[i]; }
    }
    std::cout << "[MateriaSource] Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void MateriaSource::learnMateria( AMateria *materia ) {
    for ( int i = 0; i < _nMaterias; i++ ) {
        if ( !_materias[i] ) {
            _materias[i] = materia;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria( std::string const &type ) {
    for ( int i = 0; i < _nMaterias; i++ ) {
        if ( type == _materias[i]->getType() ) { return _materias[i]->clone(); }
    }
    return NULL;
}

void MateriaSource::print( std::ostream &os ) const {
    bool printed = false;
    os << "[";
    for ( int i = 0; i < _nMaterias; i++ ) {
        if ( _materias[i] ) {
            if ( printed ) { os << ","; }
            os << " " << *( _materias[i] ) << " ";
            printed = true;
        }
    }
    os << "]";
}

/* -------------------------------------------------------------------------- */
