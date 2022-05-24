#include "DiamondTrap.hpp"

/* -------------------------------------------------------------------------- */

DiamondTrap::DiamondTrap() {
    _hitPoints    = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;

    std::cout << "[DiamondTrap] Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string const name )
    : ClapTrap( name + "_clap_trap" ) {
    _name         = name;
    _hitPoints    = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "[DiamondTrap] Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &other )
    : ClapTrap( other._name ) {
    *this = other;
    std::cout << "[DiamondTrap] Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=( DiamondTrap const &other ) {
    FragTrap::operator=( other );
    ScavTrap::operator=( other );
    _name = other._name;

    std::cout << "[DiamondTrap] Copy assignment operator called" << std::endl;

    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "[DiamondTrap] Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void DiamondTrap::attack( std::string const &target ) {
    ScavTrap::attack( target );
}

/* -------------------------------------------------------------------------- */

void DiamondTrap::guardGate() {
    if ( _hitPoints ) {
        std::cout << "[DiamondTrap] Entering now in the guate keeper mode"
                  << std::endl;
    }
}

/* -------------------------------------------------------------------------- */

void DiamondTrap::whoAmI() {
    std::cout << "[DiamondTrap] "
              << "I'am " << _name << " and my grandmother is "
              << ClapTrap::_name << std::endl;
}

/* -------------------------------------------------------------------------- */
