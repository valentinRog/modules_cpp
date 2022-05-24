#include "ScavTrap.hpp"
#include <iostream>

int main() {
    ScavTrap  robot1( "robot1" );
    ClapTrap *robot2 = new ClapTrap( "robot2" );

    std::cout << std::endl;
    std::cout << robot1 << std::endl;
    std::cout << *robot2 << std::endl;
    std::cout << std::endl;

    robot1.attack( "robot2" );
    robot2->takeDamage( 0 );
    std::cout << robot1 << std::endl;
    std::cout << *robot2 << std::endl;
    std::cout << std::endl;

    robot1.beRepaired( 5 );
    std::cout << robot1 << std::endl;
    std::cout << *robot2 << std::endl;
    std::cout << std::endl;

    robot2->takeDamage( 20 );
    robot2->takeDamage( 100 );
    robot2->beRepaired( 200 );
    std::cout << robot1 << std::endl;
    std::cout << *robot2 << std::endl;
    std::cout << std::endl;

    delete robot2;

    return 0;
}
