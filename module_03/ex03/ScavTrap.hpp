#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

protected:
    static unsigned int const _defaultHitPoints;
    static unsigned int const _defaultEnergyPoints;
    static unsigned int const _defaultAttackDamage;

public:
    ScavTrap();
    ScavTrap( std::string const name );
    ScavTrap( ScavTrap const &other );
    ScavTrap &operator=( ScavTrap const &other );
    ~ScavTrap();

    void attack( std::string const &target );

    void guardGate();
};

std::ostream &operator<<( std::ostream &os, ScavTrap const &scavTrap );

#endif
