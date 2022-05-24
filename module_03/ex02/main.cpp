#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main( void ) {

    ClapTrap claptrap( "robot1" );
    FragTrap fragTrap( "robot2" );

    std::cout << fragTrap << std::endl;

    std::cout << std::endl;

    claptrap.attack( "robot2" );
    fragTrap.takeDamage( 0 );
    fragTrap.beRepaired( 18 );

    std::cout << std::endl;

    fragTrap.attack( "robot1" );
    claptrap.takeDamage( 20 );
    fragTrap.attack( "robot1" );
    claptrap.takeDamage( 20 );
    fragTrap.attack( "robot1" );
    claptrap.beRepaired( 64 );

    std::cout << std::endl;

    fragTrap.highFivesGuys();
    fragTrap.attack( "robot1" );

    std::cout << std::endl;

    fragTrap.takeDamage( 100 );
    fragTrap.takeDamage( 1 );
    fragTrap.attack( "robot2" );
    fragTrap.beRepaired( 200 );

    std::cout << std::endl;

    return ( 0 );
}
