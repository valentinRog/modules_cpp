#include "Cat.hpp"

/* -------------------------------------------------------------------------- */

Cat::Cat() {
    _type  = "Cat";
    _brain = new Brain();
    std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat( Cat const &other ) : AAnimal(), _brain( 0 ) {
    std::cout << "[Cat] Copy constructor called" << std::endl;
    *this = other;
}

Cat &Cat::operator=( Cat const &other ) {
    _type = other._type;
    if ( _brain ) { delete _brain; }
    _brain = new Brain( *other._brain );
    std::cout << "[Cat] Copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "[Cat] Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */

void Cat::makeSound() const { std::cout << "[Cat] Meow..." << std::endl; }

/* -------------------------------------------------------------------------- */

void Cat::addIdea( std::string const &idea ) { _brain->add( idea ); }

/* -------------------------------------------------------------------------- */

void Cat::print( std::ostream &os ) const {
    os << "{ ";
    os << "type: "
       << "\"" << _type << "\", ";
    os << "brain: " << *_brain;
    os << " }";
}

/* -------------------------------------------------------------------------- */
