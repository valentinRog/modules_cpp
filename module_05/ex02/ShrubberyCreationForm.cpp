#include "ShrubberyCreationForm.hpp"

/* -------------------------------------------------------------------------- */

int const ShrubberyCreationForm::_gradeToSign    = 145;
int const ShrubberyCreationForm::_gradeToExecute = 137;

std::string const ShrubberyCreationForm::_asciiTree
    = "  (ooo ooooo)\n"
      " (ooooo oo0oo)\n"
      "  (oo0o0o0oo)\n"
      "      ||\n"
      "      /|\n"
      "    _/||\\_\n";

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

void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
    check_executability( executor );
    std::ofstream oFile;
    oFile.open( ( _target + "_shrubbery" ).c_str(), std::ios::out );
    oFile << _asciiTree;
}

/* -------------------------------------------------------------------------- */

void ShrubberyCreationForm::print( std::ostream &os ) const {
    os << "{ ";
    os << "name: \"" << getName() << "\", ";
    os << "signed: " << getSigned() << ", ";
    os << "gradeRequired: " << getGradeToSign() << ", ";
    os << "gradeToExecute: " << getGradeToExecute() << ", ";
    os << "target: \"" << _target << "\"";
    os << " }";
}

/* -------------------------------------------------------------------------- */
