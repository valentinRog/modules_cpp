#include "Dog.hpp"

/* -------------------------------------------------------------------------- */

Dog::Dog() {
    _type  = "Dog";
    _brain = new Brain();
    std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog( Dog const &other ) : AAnimal(), _brain( NULL ) {
    std::cout << "[Dog] Copy constructor called" << std::endl;
    *this = other;
}

Dog &Dog::operator=( Dog const &other ) {
    _type = other._type;
    if ( _brain ) { delete _brain; }
    _brain = new Brain( *other._brain );
    std::cout << "[Dog] Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "[Dog] Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void Dog::makeSound() const { std::cout << "[Dog] Woaf !" << std::endl; }

/* -------------------------------------------------------------------------- */

void Dog::addIdea( std::string const &idea ) { _brain->add( idea ); }

/* -------------------------------------------------------------------------- */

void Dog::print( std::ostream &os ) const {
    os << "{ ";
    os << "type: "
       << "\"" << _type << "\", ";
    os << "brain: " << *_brain;
    os << " }";
}

/* -------------------------------------------------------------------------- */
