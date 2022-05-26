#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

protected:
	std::string _type;

public:
	Animal();
	Animal(Animal const & other);
	Animal &operator=(Animal const & other);
	virtual ~Animal();

	virtual void makeSound() const;
};

#endif
