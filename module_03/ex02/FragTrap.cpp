#include "FragTrap.hpp"

/* -------------------------------------------------------------------------- */

FragTrap::FragTrap() {
    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "[FragTrap] Default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string const name ) {
    _name = name;

    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "[FragTrap] Constructor called" << std::endl;
}

FragTrap::FragTrap( FragTrap const &other ) : ClapTrap( other._name ) {
    *this = other;
    std::cout << "[FragTrap] Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=( FragTrap const &other ) {
    ClapTrap::operator=( other );

    std::cout << "[FragTrap] Copy assignment operator called" << std::endl;

    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "[FragTrap] Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void FragTrap::attack( std::string const &target ) {
    if ( _energyPoints && _hitPoints ) {
        std::cout << "[FragTrap] " << _name << " 🏹 " << target << " (-" << _attackDamage
                  << "💚)" << std::endl;

        _energyPoints--;
    }
}

/* -------------------------------------------------------------------------- */

void FragTrap::guardGate() {
    if ( _hitPoints ) {
        std::cout << "[FragTrap] Entering now in the guate keeper mode" << std::endl;
    }
}

void FragTrap::highFivesGuys() {
    if ( _hitPoints ) {
        std::cout << "[FragTrap] High five ?" << std::endl;
    }
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, FragTrap const &fragTrap ) {
    os << "[FragTrap] ";
    fragTrap.print( os );

    return os;
}

/* -------------------------------------------------------------------------- */
