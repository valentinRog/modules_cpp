#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    Animal *dog = new Dog();
    std::cout << std::endl;

    dog->addIdea( "dog idea #1" );
    dog->addIdea( "dog idea #2" );
    dog->addIdea( "dog idea #3" );
    dog->addIdea( "dog idea #4" );

    Cat cat;
    std::cout << std::endl;

    cat.addIdea( "cat idea #1" );
    cat.addIdea( "cat idea #2" );

    int const arrSize = 6;
    Animal *  arr[arrSize];

    for ( int i = 0; i < arrSize; i++ ) {
        if ( i % 2 ) {
            arr[i] = new Cat( cat );
        } else {
            arr[i]      = new Dog();
            *static_cast<Dog*>(arr[i]) = *static_cast<Dog*>(dog);
        }
    }
    std::cout << std::endl;
    delete dog;
    std::cout << std::endl;

    for ( int i = 0; i < arrSize; i++ ) {
        std::cout << *( arr[i] ) << std::endl;
    }
    std::cout << std::endl;

    for ( int i = 0; i < arrSize; i++ ) { delete arr[i]; }

    return 0;
}
