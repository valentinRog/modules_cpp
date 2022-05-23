#include "ClapTrap.hpp"
#include <iostream>

int	main(  )
{
	ClapTrap clapTrap("robot1");

	clapTrap.attack("robot2");
	clapTrap.takeDamage(9);
	clapTrap.beRepaired(3);
	clapTrap.takeDamage(2);
	clapTrap.takeDamage(100);
	clapTrap.beRepaired(20);
	clapTrap.attack("robot3");

	return 0;
}
