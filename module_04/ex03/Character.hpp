#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter {

private:
    std::string _name;

    static int const _nSlots = 4;

    AMateria *_inventory[_nSlots];

public:
    Character();
    Character( std::string const &name );
    Character( Character const &other );
    Character &operator=( Character const &other );
    ~Character();

    virtual std::string const &getName() const;
    virtual void               equip( AMateria *m );
    virtual void               unequip( int idx );
    virtual void               use( int idx, ICharacter &target );

    void print( std::ostream &os ) const;
};

#endif
