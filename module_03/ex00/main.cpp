#include "ClapTrap.hpp"
#include <iostream>

int	main(  )
{
	ClapTrap clapTrap("clapTrap");

	clapTrap.attack("anotherClapTrap");
	clapTrap.takeDamage(9);
	clapTrap.beRepaired(3);
	clapTrap.takeDamage(2);
	clapTrap.takeDamage(100);
	clapTrap.beRepaired(20);
	clapTrap.attack("anotherClapTrap");

	return 0;
}
