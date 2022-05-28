#include "ScavTrap.hpp"

/* -------------------------------------------------------------------------- */

unsigned int const ScavTrap::_defaultHitPoints    = 100;
unsigned int const ScavTrap::_defaultEnergyPoints = 50;
unsigned int const ScavTrap::_defaultAttackDamage = 20;

/* -------------------------------------------------------------------------- */

ScavTrap::ScavTrap()
    : ClapTrap( _defaultHitPoints,
                _defaultEnergyPoints,
                _defaultAttackDamage ) {
    std::cout << "[ScavTrap] Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string const name )
    : ClapTrap( _defaultHitPoints,
                _defaultEnergyPoints,
                _defaultAttackDamage ) {
    _name = name;
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
        std::cout << "[ScavTrap] " << _name << " 🏹 " << target << " (-"
                  << _attackDamage << "💚)" << std::endl;

        _energyPoints--;
    }
}

/* -------------------------------------------------------------------------- */

void ScavTrap::guardGate() {
    if ( _hitPoints ) {
        std::cout << "[ScavTrap] Entering now in the guate keeper mode"
                  << std::endl;
    }
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, ScavTrap const &scavTrap ) {
    os << "[ScavTrap] ";
    scavTrap.print( os );

    return os;
}

/* -------------------------------------------------------------------------- */
