#include "ScavTrap.hpp"

/* -------------------------------------------------------------------------- */

ScavTrap::ScavTrap() {
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;

    std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string const name ) {
    _name = name;

    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;

    std::cout << "ScavTrap: Constructor called" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &other ) : ClapTrap( other._name ) {
    *this = other;
    std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=( ScavTrap const &other ) {
    ClapTrap::operator=( other );

    std::cout << "ScavTrap: Copy assignment operator called" << std::endl;

    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
