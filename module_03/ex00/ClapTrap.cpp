#include "ClapTrap.hpp"

/* -------------------------------------------------------------------------- */

ClapTrap::ClapTrap()
    : _hitPoints( 10 ),
      _energyPoints( 10 ),
      _attackDamage( 0 ) {
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string const name )
    : _name( name ),
      _hitPoints( 10 ),
      _energyPoints( 10 ),
      _attackDamage( 0 ) {
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &other ) {
    *this = other;

    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=( ClapTrap const &other ) {
    _name         = other._name;
    _hitPoints    = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;

    std::cout << "Copy assignment operator called" << std::endl;

    return *this;
}

ClapTrap::~ClapTrap() { std::cout << "Destructor called" << std::endl; }

/* -------------------------------------------------------------------------- */

void ClapTrap::attack( const std::string &target ) {
    if ( _energyPoints && _hitPoints ) {
        std::cout << _name << " 🔫  " << target << " (-" << _attackDamage
                  << " 💛)" << std::endl;

        _energyPoints--;
    }
}

void ClapTrap::takeDamage( unsigned int amount ) {
    if ( _hitPoints ) {
        std::cout << _name << " -" << amount << " 💛" << std::endl;

        if ( amount <= _hitPoints ) {
            _hitPoints -= amount;
        } else {
            _hitPoints = 0;
            std::cout << _name << " 💀" << std::endl;
        }
    }
}

void ClapTrap::beRepaired( unsigned int amount ) {
    if ( _energyPoints && _hitPoints ) {
        std::cout << _name << " +" << amount << " 💚" << std::endl;

        _hitPoints += amount;
        _energyPoints--;
    }
}

/* -------------------------------------------------------------------------- */
