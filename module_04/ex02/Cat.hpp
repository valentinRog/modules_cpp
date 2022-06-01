#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

private:
	Brain *_brain;

public:
	Cat();
	Cat(Cat const & other);
	Cat &operator=(Cat const & other);
	~Cat();

	void makeSound() const;

	void addIdea(std::string const &idea);

	void print(std::ostream &os) const;
};

#endif
