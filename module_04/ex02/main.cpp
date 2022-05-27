#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

	// AAnimal aAnimal;
	// AAnimal *aAnimal = new AAnimal;

    AAnimal *dog = new Dog();
    std::cout << std::endl;

    dog->addIdea( "dog idea #1" );
    dog->addIdea( "dog idea #2" );
    dog->addIdea( "dog idea #3" );
    dog->addIdea( "dog idea #4" );

    std::cout << *dog << std::endl;
    std::cout << std::endl;

    delete dog;
    std::cout << std::endl;

	Cat cat1;
	Cat cat2;
	std::cout << std::endl;

	cat1.addIdea("cat1 idea #1");
	cat1.addIdea("cat1 idea #2");
	cat2.addIdea("cat2 idea #1");

	std::cout << cat1 << std::endl;
	std::cout << cat2 << std::endl;
	std::cout << std::endl;

	cat2 = cat1;
	std::cout << std::endl;

	std::cout << cat1 << std::endl;
	std::cout << cat2 << std::endl;
	std::cout << std::endl;

    return 0;
}
