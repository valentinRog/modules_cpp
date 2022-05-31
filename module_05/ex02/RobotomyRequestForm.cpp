#include "RobotomyRequestForm.hpp"

/* -------------------------------------------------------------------------- */

int const RobotomyRequestForm::_gradeToSign    = 72;
int const RobotomyRequestForm::_gradeToExecute = 45;

/* -------------------------------------------------------------------------- */

RobotomyRequestForm::RobotomyRequestForm()
    : Form( "RobotomyRequestForm", _gradeToSign, _gradeToExecute ) {}

RobotomyRequestForm::RobotomyRequestForm( std::string const &target )
    : Form( "RobotomyRequestForm", _gradeToSign, _gradeToExecute ),
      _target( target ) {}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &other )
    : Form( other ),
      _target( other._target ) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=( const RobotomyRequestForm &other ) {
    Form::operator=( other );
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

/* -------------------------------------------------------------------------- */

void RobotomyRequestForm::execute( Bureaucrat const &executor ) const {
    check_executability( executor );
    std::cout << "* drilling noises *" << std::endl;
    if ( std::rand() % 2 ) {
        std::cout << _target << " has been robotomized" << std::endl;
    } else {
        std::cout << _target << " hasn't been robotomized" << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
