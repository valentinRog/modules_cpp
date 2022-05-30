
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {

    IMateriaSource *src = new MateriaSource();
    std::cout << std::endl;

    src->learnMateria( new Ice() );
    std::cout << *src << std::endl;
    src->learnMateria( new Cure() );
    std::cout << *src << std::endl;
    src->learnMateria( new Ice() );
    std::cout << *src << std::endl;
    std::cout << std::endl;

    ICharacter *c1 = new Character( "c1" );
    std::cout << *c1 << std::endl;
    std::cout << std::endl;

    c1->equip(src->createMateria( "ice" ));
    std::cout << *c1 << std::endl;
    std::cout << std::endl;

    c1->equip(src->createMateria( "cure" ));
    std::cout << *c1 << std::endl;
    std::cout << std::endl;

    ICharacter *c2 = new Character( "c2" );
    std::cout << *c2 << std::endl;
    std::cout << std::endl;

    c1->use( 0, *c2 );
    c1->use( 1, *c2 );
    std::cout <<std::endl;

    delete src;
    delete c1;
    delete c2;

    return 0;
}