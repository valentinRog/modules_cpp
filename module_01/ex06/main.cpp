#include <iostream>
#include <string>

#include "Harl.hpp"

int main( int argc, char **argv ) {
	if ( argc != 2 ) {
		std::cerr << "Error: 1 positional argument required" << std::endl;
		return 1;
	}

	Harl		harl;
	std::string level( argv[1] );
	int			index = harl.get_level_index( level );

	switch ( index ) {
	case 0:
		harl.complainFilter( 0b1111 );
		break;
	case 1:
		harl.complainFilter( 0b1110 );
		break;
	case 2:
		harl.complainFilter( 0b1100 );
		break;
	case 3:
		harl.complainFilter( 0b1000 );
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]"
				  << std::endl;
	}
}
