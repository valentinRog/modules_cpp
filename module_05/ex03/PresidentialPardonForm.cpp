#include "PresidentialPardonForm.hpp"

/* -------------------------------------------------------------------------- */

int const PresidentialPardonForm::_gradeToSign    = 25;
int const PresidentialPardonForm::_gradeToExecute = 5;

/* -------------------------------------------------------------------------- */

PresidentialPardonForm::PresidentialPardonForm()
    : Form( "PresidentialPardonForm", _gradeToSign, _gradeToExecute ) {}

PresidentialPardonForm::PresidentialPardonForm( std::string const &target )
    : Form( "PresidentialPardonForm", _gradeToSign, _gradeToExecute ),
      _target( target ) {}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &other )
    : Form( other ),
      _target( other._target ) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=( const PresidentialPardonForm &other ) {
    Form::operator=( other );
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

/* -------------------------------------------------------------------------- */

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    check_executability(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/* -------------------------------------------------------------------------- */
