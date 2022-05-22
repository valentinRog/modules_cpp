#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void ) {

    ClapTrap claptrap( "robot1" );
    ScavTrap scavtrap( "robot2" );

    std::cout << std::endl;

    claptrap.attack( "robot2" );
    scavtrap.takeDamage( 0 );
    scavtrap.beRepaired( 18 );

    std::cout << std::endl;

    scavtrap.attack( "robot1" );
    claptrap.takeDamage( 20 );
    scavtrap.attack( "robot1" );
    claptrap.takeDamage( 20 );
    scavtrap.attack( "robot1" );
    claptrap.beRepaired( 64 );

    std::cout << std::endl;

    scavtrap.guardGate();
    scavtrap.attack( "robot1" );

    std::cout << std::endl;

    scavtrap.takeDamage( 100 );
    scavtrap.takeDamage( 1 );
    scavtrap.attack( "robot2" );
    scavtrap.beRepaired( 200 );

    std::cout << std::endl;

    return ( 0 );
}
