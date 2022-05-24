#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

protected:
    std::string _name;

    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;


public:
    ClapTrap();
    ClapTrap( std::string const name );
    ClapTrap( ClapTrap const &other );
    ClapTrap &operator=( ClapTrap const &other );
    ~ClapTrap();

    void attack( std::string const &target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );

    void print(std::ostream &os) const;
};

std::ostream &operator<<( std::ostream &os, ClapTrap const &ClapTrap );

#endif
