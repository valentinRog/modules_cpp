#include "ShrubberyCreationForm.hpp"

/* -------------------------------------------------------------------------- */

int const ShrubberyCreationForm::_gradeToSign    = 145;
int const ShrubberyCreationForm::_gradeToExecute = 137;

/* -------------------------------------------------------------------------- */

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form( "ShrubberyCreationForm", _gradeToSign, _gradeToExecute ) {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target )
    : Form( "ShrubberyCreationForm", _gradeToSign, _gradeToExecute ),
      _target( target ) {}

ShrubberyCreationForm::ShrubberyCreationForm(
    ShrubberyCreationForm const &other )
    : Form( other ),
      _target( other._target ) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other ) {
    Form::operator=( other );
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

/* -------------------------------------------------------------------------- */
