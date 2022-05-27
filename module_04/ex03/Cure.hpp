#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {

public:
    Cure();
    Cure( Cure const &src );
    Cure &operator=( Cure const &other );
    ~Cure();

    virtual AMateria *clone() const;
    virtual void      use( ICharacter &target );
};

#endif
