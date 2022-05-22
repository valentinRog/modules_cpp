#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"
#include <iostream>

int main( void ) {

    ClapTrap claptrap( "robot1" );
    FlagTrap flagTrap( "robot2" );

    std::cout << std::endl;

    claptrap.attack( "robot2" );
    flagTrap.takeDamage( 0 );
    flagTrap.beRepaired( 18 );

    std::cout << std::endl;

    flagTrap.attack( "robot1" );
    claptrap.takeDamage( 20 );
    flagTrap.attack( "robot1" );
    claptrap.takeDamage( 20 );
    flagTrap.attack( "robot1" );
    claptrap.beRepaired( 64 );

    std::cout << std::endl;

    flagTrap.highFivesGuys();
    flagTrap.attack( "robot1" );

    std::cout << std::endl;

    flagTrap.takeDamage( 100 );
    flagTrap.takeDamage( 1 );
    flagTrap.attack( "robot2" );
    flagTrap.beRepaired( 200 );

    std::cout << std::endl;

    return ( 0 );
}
