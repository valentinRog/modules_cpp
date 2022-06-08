#include "Zombie.hpp"

int main() {
    {
        Zombie zombieOnStack( "zombieOnStack" );
        zombieOnStack.announce();
    }
    std::cout << std::endl;
    {
        Zombie *zombieOnHeap = newZombie( "zombieOnHeap" );
        zombieOnHeap->announce();
        delete zombieOnHeap;
    }
    std::cout << std::endl;
    { randomChump( "randomZombie" ); }
    return 0;
}
