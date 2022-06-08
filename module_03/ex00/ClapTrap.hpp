#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

private:
    static unsigned int const _defaultHitPoints;
    static unsigned int const _defaultEnergyPoints;
    static unsigned int const _defaultAttackDamage;

    std::string _name;

    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    ClapTrap();
    ClapTrap( std::string const &name );
    ClapTrap( unsigned int hitPoints,
              unsigned int energyPoints,
              unsigned int attackDamage );
    ClapTrap( std::string const &name,
              unsigned int       hitPoints,
              unsigned int       energyPoints,
              unsigned int       attackDamage );
    ClapTrap( ClapTrap const &other );
    ClapTrap &operator=( ClapTrap const &other );
    virtual ~ClapTrap();

    virtual void attack( std::string const &target );
    void         takeDamage( unsigned int amount );
    void         beRepaired( unsigned int amount );

    virtual void print( std::ostream &os ) const;
};

std::ostream &operator<<( std::ostream &os, ClapTrap const &ClapTrap );

#endif
