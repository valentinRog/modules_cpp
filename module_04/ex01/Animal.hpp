#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

protected:
    std::string _type;

public:
    Animal();
    Animal( Animal const &other );
    Animal &operator=( Animal const &other );
    virtual ~Animal();

	std::string const &getType() const;

    virtual void makeSound() const;

    virtual void addIdea(std::string const &idea);

    virtual void print(std::ostream &os) const;
};

std::ostream &operator<<( std::ostream &os, Animal const & animal);

#endif
