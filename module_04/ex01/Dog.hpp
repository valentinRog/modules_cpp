#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

private:
    Brain *_brain;

public:
    Dog();
    Dog( Dog const &other );
    Dog &operator=( Dog const &other );
    ~Dog();

    void makeSound() const;

    void addIdea(std::string const &idea);

    void print(std::ostream &os) const;
};

#endif
