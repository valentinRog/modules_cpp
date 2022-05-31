#include "Intern.hpp"

/* -------------------------------------------------------------------------- */

int const         Intern::_formCount = 3;
std::string const Intern::_formStr[]
    = { "shrubbery creation", "robotomy request", "presidential pardon" };

/* -------------------------------------------------------------------------- */

int Intern::_get_index( std::string const &name ) {
    for ( int i = 0; i < _formCount; i++ ) {
        if ( name == _formStr[i] ) { return i; }
    }
    return -1;
}

/* -------------------------------------------------------------------------- */

Intern::Intern() {}

Intern::Intern( Intern const &other ) { *this = other; }

Intern &Intern::operator=( Intern const &other ) {
    ( void ) other;
    return *this;
}

Intern::~Intern() {}

/* -------------------------------------------------------------------------- */

const char *Intern::FormNotFoundException::what() const throw() {
    return "form not found";
}

/* -------------------------------------------------------------------------- */

Form *Intern::makeForm( std::string const &name,
                        std::string const &target ) const {
    int index = _get_index( name );

    switch ( index ) {
    case SHRUBBERY_CREATION:
        return new ShrubberyCreationForm( target );
    case ROBOTOMY_REQUEST:
        return new RobotomyRequestForm( target );
    case PRESIDENTIAL_PARDON:
        return new PresidentialPardonForm( target );
    default:
        throw FormNotFoundException();
    }
}

/* -------------------------------------------------------------------------- */
