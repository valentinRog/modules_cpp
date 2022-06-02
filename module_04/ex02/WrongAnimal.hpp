#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {

protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal( WrongAnimal const &other );
    WrongAnimal &operator=( WrongAnimal const &other );
    virtual ~WrongAnimal();

	std::string const &getType() const;

    void makeSound() const;

    void print(std::ostream &os) const;
};

std::ostream &operator<<( std::ostream &os, WrongAnimal const & wrongAnimal);

#endif
