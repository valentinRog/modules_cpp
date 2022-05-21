#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(  )
{
	ScavTrap scavTrap("scavTrap");

	scavTrap.attack("anotherScavTrap");
	scavTrap.takeDamage(9);
	scavTrap.beRepaired(3);
	scavTrap.takeDamage(2);
	scavTrap.takeDamage(100);
	scavTrap.beRepaired(20);
	scavTrap.attack("anotherScavTrap");

	return 0;
}
