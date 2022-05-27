#include "Character.hpp"

/* -------------------------------------------------------------------------- */

Character::Character() {
    for ( int i = 0; i < _nSlots; i++ ) { _inventory[i] = NULL; }
}

Character::Character( std::string const &name ) : _name( name ) {
    for ( int i = 0; i < _nSlots; i++ ) { _inventory[i] = NULL; }
}

Character::Character( Character const &other ) { *this = other; }

Character &Character::operator=( Character const &other ) {
    _name = other._name;
    for ( int i = 0; i < _nSlots; i++ ) {
        if ( _inventory[i] ) { delete _inventory[i]; }
        _inventory[i] = other._inventory[i];
    }
    return *this;
}

Character::~Character() {
    for ( int i = 0; i < _nSlots; i++ ) {
        if ( _inventory[i] ) { delete _inventory[i]; }
    }
}

/* -------------------------------------------------------------------------- */

std::string const &Character::getName() const { return _name; }

void Character::equip( AMateria *m ) {
    for ( int i = 0; i < _nSlots; i++ ) {
        if ( !_inventory[i] ) {
            _inventory[i] = m;
            break;
        }
    }
}

void Character::unequip( int idx ) {
    if ( idx >= 0 && idx < _nSlots ) { _inventory[idx] = NULL; }
}

void Character::use( int idx, ICharacter &target ) {
    if ( idx >= 0 && idx < _nSlots ) { _inventory[idx]->use( target ); }
}

/* -------------------------------------------------------------------------- */
