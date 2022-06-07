#include "Character.hpp"

/* -------------------------------------------------------------------------- */

Character::Character() {
    for ( int i = 0; i < _nSlots; i++ ) { _inventory[i] = 0; }
    std::cout << "[Character] Default constructor called" << std::endl;
}

Character::Character( std::string const &name ) : _name( name ) {
    for ( int i = 0; i < _nSlots; i++ ) { _inventory[i] = 0; }
    std::cout << "[Character] Constructor called" << std::endl;
}

Character::Character( Character const &other ) {
    for ( int i = 0; i < _nSlots; i++ ) { _inventory[i] = 0; }
    *this = other;
    std::cout << "[Character] Copy constructor called" << std::endl;
}

Character &Character::operator=( Character const &other ) {
    _name = other._name;
    for ( int i = 0; i < _nSlots; i++ ) {
        if ( _inventory[i] ) { delete _inventory[i]; }
        if ( other._inventory[i] ) {
            _inventory[i] = other._inventory[i]->clone();
        }
    }
    std::cout << "[Character] Copy assignment operator called" << std::endl;
    return *this;
}

Character::~Character() {
    for ( int i = 0; i < _nSlots; i++ ) {
        if ( _inventory[i] ) { delete _inventory[i]; }
    }
    std::cout << "[Character] Destructor called" << std::endl;
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
    if ( idx >= 0 && idx < _nSlots ) { _inventory[idx] = 0; }
}

void Character::use( int idx, ICharacter &target ) {
    if ( idx >= 0 && idx < _nSlots ) { _inventory[idx]->use( target ); }
}

/* -------------------------------------------------------------------------- */

void Character::print( std::ostream &os ) const {
    os << "{ ";
    os << "name: "
       << "\"" << _name << "\" , ";
    os << "inventory: ";
    {
        bool printed = false;
        os << "[";
        for ( int i = 0; i < _nSlots; i++ ) {
            if ( _inventory[i] ) {
                if ( printed ) { os << ","; }
                os << " " << *( _inventory[i] ) << " ";
                printed = true;
            }
        }
        os << "]";
    }
    os << " }";
}

/* -------------------------------------------------------------------------- */
