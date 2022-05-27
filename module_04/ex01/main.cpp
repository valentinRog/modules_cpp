#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
Animal* dog = new Dog();
Animal* cat = new Cat();

dog->addIdea("yo");
dog->addIdea("les");
dog->addIdea("fdp");
dog->addIdea("haha");

Dog dog1;
dog1.addIdea("yo");
Dog dog2(dog1);
dog2 = dog1;
dog2.addIdea("yo");

std::cout << *dog << std::endl;
std::cout << dog1 << std::endl;
std::cout << dog2 << std::endl;

delete dog;
delete cat;

return 0;
}
