#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {

private:
    std::string _name;
    Weapon     *_weapon;

public:
    HumanB( std::string name );

    void setWeapon( Weapon &weapon );

    void attack();
};

#endif
