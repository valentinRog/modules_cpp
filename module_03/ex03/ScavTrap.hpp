#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:
	ScavTrap();
    ScavTrap( std::string const name );
    ScavTrap( ScavTrap const &other );
    ScavTrap &operator=( ScavTrap const &other );
    ~ScavTrap();

    void attack( const std::string &target );

    void guardGate();
};

#endif
