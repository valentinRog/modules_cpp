#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    Animal *     animal      = new Animal();
    Animal *     dog         = new Dog();
    Animal *     cat         = new Cat();
    WrongAnimal *wrongAnimal = new WrongCat();

    std::cout << std::endl;

    std::cout << *animal << std::endl;
    std::cout << *dog << std::endl;
    std::cout << *cat << std::endl;
    std::cout << *wrongAnimal << std::endl;

    std::cout << std::endl;

    animal->makeSound();
    dog->makeSound();
    cat->makeSound();
    wrongAnimal->makeSound();

    std::cout << std::endl;

    delete animal;
    delete dog;
    delete cat;

    return 0;
}
