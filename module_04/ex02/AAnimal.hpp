#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {

protected:
    std::string _type;

public:
    AAnimal();
    AAnimal( AAnimal const &other );
    AAnimal &operator=( AAnimal const &other );
    virtual ~AAnimal();

    std::string const &getType() const;

    virtual void makeSound() const = 0;

    virtual void addIdea( std::string const &idea ) = 0;

    virtual void print( std::ostream &os ) const = 0;
};

std::ostream &operator<<( std::ostream &os, AAnimal const &aanimal );

#endif
