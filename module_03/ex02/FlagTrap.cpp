#include "FlagTrap.hpp"

/* -------------------------------------------------------------------------- */

FlagTrap::FlagTrap() {
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;

    std::cout << "[FlagTrap] "
              << "Default constructor called" << std::endl;
}

FlagTrap::FlagTrap( std::string const name ) {
    _name = name;

    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;

    std::cout << "[FlagTrap] "
              << "Constructor called" << std::endl;
}

FlagTrap::FlagTrap( FlagTrap const &other ) : ClapTrap( other._name ) {
    *this = other;
    std::cout << "[FlagTrap] "
              << "Copy constructor called" << std::endl;
}

FlagTrap &FlagTrap::operator=( FlagTrap const &other ) {
    ClapTrap::operator=( other );

    std::cout << "[FlagTrap] "
              << "Copy assignment operator called" << std::endl;

    return *this;
}

FlagTrap::~FlagTrap() {
    std::cout << "[FlagTrap] "
              << "Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void FlagTrap::attack( const std::string &target ) {
    if ( _energyPoints && _hitPoints ) {
        std::cout << _name << " 🏹 " << target << " (-" << _attackDamage
                  << "💚)" << std::endl;

        _energyPoints--;
    }
}

/* -------------------------------------------------------------------------- */

void FlagTrap::guardGate() {
    if ( _hitPoints ) {
        std::cout << "FlagTrap is now in the guate keeper mode" << std::endl;
    }
}

void FlagTrap::highFivesGuys() {
    if ( _hitPoints ) {
        std::cout << "High five ?" << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
