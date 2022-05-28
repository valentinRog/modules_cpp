#ifndef FLAG_TRAP_HPP
#define FLAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

protected:
    static unsigned int const _defaultHitPoints;
    static unsigned int const _defaultEnergyPoints;
    static unsigned int const _defaultAttackDamage;

public:
    FragTrap();
    FragTrap( std::string const name );
    FragTrap( FragTrap const &other );
    FragTrap &operator=( FragTrap const &other );
    ~FragTrap();

    void attack( std::string const &target );

    void guardGate();
    void highFivesGuys();
};

std::ostream &operator<<( std::ostream &os, FragTrap const &fragTrap );

#endif
