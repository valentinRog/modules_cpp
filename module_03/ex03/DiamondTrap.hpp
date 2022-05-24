#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include <iostream>
#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {

private:
	std::string _name;

public:
	DiamondTrap();
    DiamondTrap( std::string const name );
    DiamondTrap( DiamondTrap const &other );
    DiamondTrap &operator=( DiamondTrap const &other );
    ~DiamondTrap();

	void attack(std::string const &target);

    void guardGate();

    void whoAmI();

    void print(std::ostream &os) const;
};

std::ostream &operator<<( std::ostream &os, DiamondTrap const &diamondTrap );

#endif
