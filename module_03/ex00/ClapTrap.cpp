#include "ClapTrap.hpp"

/* -------------------------------------------------------------------------- */

unsigned int const ClapTrap::_defaultHitPoints    = 10;
unsigned int const ClapTrap::_defaultEnergyPoints = 10;
unsigned int const ClapTrap::_defaultAttackDamage = 0;

/* -------------------------------------------------------------------------- */

ClapTrap::ClapTrap()
    : _hitPoints( _defaultHitPoints ),
      _energyPoints( _defaultEnergyPoints ),
      _attackDamage( _defaultAttackDamage ) {
    std::cout << "[ClapTrap] Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string const &name )
    : _name( name ),
      _hitPoints( _defaultHitPoints ),
      _energyPoints( _defaultEnergyPoints ),
      _attackDamage( _defaultAttackDamage ) {
    std::cout << "[ClapTrap] Constructor called" << std::endl;
}

ClapTrap::ClapTrap( unsigned int hitPoints,
                    unsigned int energyPoints,
                    unsigned int attackDamage )
    : _hitPoints( hitPoints ),
      _energyPoints( energyPoints ),
      _attackDamage( attackDamage ) {
    std::cout << "[ClapTrap] Constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string const &name,
                    unsigned int       hitPoints,
                    unsigned int       energyPoints,
                    unsigned int       attackDamage )
    : _name( name ),
      _hitPoints( hitPoints ),
      _energyPoints( energyPoints ),
      _attackDamage( attackDamage ) {
    std::cout << "[ClapTrap] Constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &other ) {
    *this = other;
    std::cout << "[ClapTrap] Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=( ClapTrap const &other ) {
    _name         = other._name;
    _hitPoints    = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "[ClapTrap] Copy assignment operator called" << std::endl;

    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "[ClapTrap] Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void ClapTrap::attack( std::string const &target ) {
    if ( _energyPoints && _hitPoints ) {
        std::cout << "[ClapTrap] " << _name << " 🔫 " << target << " (-"
                  << _attackDamage << "💚)" << std::endl;
        _energyPoints--;
    }
}

void ClapTrap::takeDamage( unsigned int amount ) {
    if ( _hitPoints ) {
        std::cout << "[ClapTrap] " << _name << " -" << amount << "💚"
                  << std::endl;
        if ( amount <= _hitPoints ) {
            _hitPoints -= amount;
        } else {
            _hitPoints = 0;
            std::cout << "[ClapTrap] " << _name << " 💀" << std::endl;
        }
    }
}

void ClapTrap::beRepaired( unsigned int amount ) {
    if ( _energyPoints && _hitPoints ) {
        std::cout << "[ClapTrap] " << _name << " +" << amount << "💚"
                  << std::endl;
        _hitPoints += amount;
        _energyPoints--;
    }
}

/* -------------------------------------------------------------------------- */

void ClapTrap::print( std::ostream &os ) const {
    os << "{ ";
    os << "name: \"" << _name << "\", ";
    os << "hitPoints: " << _hitPoints << ", ";
    os << "energyPoints: " << _energyPoints << ", ";
    os << "attackDamage: " << _attackDamage;
    os << " }";
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, ClapTrap const &clapTrap ) {
    clapTrap.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
