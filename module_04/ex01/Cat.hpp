#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

private:
	Brain *_brain;

public:
	Cat();
	Cat(Cat const & other);
	Cat &operator=(Cat const & other);
	Animal &operator=( const Animal &other );
	~Cat();

	void makeSound() const;

	void addIdea(std::string const &idea);

	void print(std::ostream &os) const;
};

#endif
