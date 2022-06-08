#include "WrongCat.hpp"

/* -------------------------------------------------------------------------- */

WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat const &other ) : WrongAnimal( other ) {
    std::cout << "[WrongCat] Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=( WrongCat const &other ) {
    WrongAnimal::operator=( other );
    std::cout << "[WrongCat] Copy assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void WrongCat::makeSound() const {
    std::cout << "[WrongCat] Meow..." << std::endl;
}

/* -------------------------------------------------------------------------- */
