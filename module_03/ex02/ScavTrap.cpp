#include "ScavTrap.hpp"

/* -------------------------------------------------------------------------- */

ScavTrap::ScavTrap() {
    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "[ScavTrap] Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string const name ) {
    _name = name;

    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;

    std::cout << "[ScavTrap] Constructor called" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &other ) : ClapTrap( other._name ) {
    *this = other;
    std::cout << "[ScavTrap] Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=( ScavTrap const &other ) {
    ClapTrap::operator=( other );

    std::cout << "[ScavTrap] Copy assignment operator called" << std::endl;

    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "[ScavTrap] Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void ScavTrap::attack( std::string const &target ) {
    if ( _energyPoints && _hitPoints ) {
        std::cout << _name << " 🏹 " << target << " (-" << _attackDamage
                  << "💚)" << std::endl;

        _energyPoints--;
    }
}

/* -------------------------------------------------------------------------- */

void ScavTrap::guardGate() {
    if ( _hitPoints ) {
        std::cout << "ScavTrap is now in the guate keeper mode" << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
