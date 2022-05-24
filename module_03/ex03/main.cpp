#include "DiamondTrap.hpp"


int	main(void)
{
	DiamondTrap dt1("yo");
	DiamondTrap dt2(dt1);

	dt1.whoAmI();
	dt2.whoAmI();
	return (0);
}