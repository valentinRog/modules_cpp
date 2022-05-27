#include "Brain.hpp"

/* -------------------------------------------------------------------------- */

Brain::Brain() : _i( 0 ) {
    std::cout << "[Brain] Default constructor called" << std::endl;
}

Brain::Brain( Brain const &other ) {
    std::cout << "[Brain] Copy constructor called" << std::endl;
    *this = other;
}

Brain &Brain::operator=( Brain const &other ) {
    std::cout << "[Brain] Copy assignment operator called" << std::endl;
    _i = other._i;
    for ( int i = 0; i < _nIdeas; i++ ) { _ideas[i] = other._ideas[i]; }
    return *this;
}

Brain::~Brain() { std::cout << "[Brain] Destructor called" << std::endl; }

/* -------------------------------------------------------------------------- */

void Brain::add( std::string const &idea ) {
    _ideas[_i] = idea;
    _i++;
    if ( _i == _nIdeas ) { _i = 0; }
}

/* -------------------------------------------------------------------------- */

void Brain::print( std::ostream &os ) const {
    bool printed = false;
    os << "[";
    for ( int i = 0; i < _nIdeas; i++ ) {
        if ( !_ideas[i].empty() ) {
            if ( printed ) { os << ","; }
            os << " \"" << _ideas[i] << "\" ";
            printed = true;
        }
    }
    os << "]";
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, Brain const &brain ) {
    brain.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
