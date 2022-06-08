#include "DiamondTrap.hpp"

/* -------------------------------------------------------------------------- */

DiamondTrap::DiamondTrap()
    : ClapTrap( FragTrap::_defaultHitPoints,
                ScavTrap::_defaultEnergyPoints,
                FragTrap::_defaultAttackDamage ) {
    std::cout << "[DiamondTrap] default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string const &name )
    : ClapTrap( name + "_clap_name",
                FragTrap::_defaultHitPoints,
                ScavTrap::_defaultEnergyPoints,
                FragTrap::_defaultAttackDamage ) {
    _name = name;
    std::cout << "[DiamondTrap] Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &other )
    : ClapTrap( other ),
      ScavTrap( other ),
      FragTrap( other ) {
    std::cout << "[DiamondTrap] Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=( DiamondTrap const &other ) {
    ClapTrap::operator=( other );
    _name             = other._name;

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

void DiamondTrap::whoAmI() {
    std::cout << "[DiamondTrap] "
              << "I'am " << _name << " and my grandmother is "
              << ClapTrap::_name << std::endl;
}

/* -------------------------------------------------------------------------- */

void DiamondTrap::print( std::ostream &os ) const {
    os << "{ ";
    os << "name: \"" << _name << "\", ";
    os << "hitPoints: " << _hitPoints << ", ";
    os << "energyPoints: " << _energyPoints << ", ";
    os << "attackDamage: " << _attackDamage;
    os << " }";
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, DiamondTrap const &diamondTrap ) {
    diamondTrap.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
