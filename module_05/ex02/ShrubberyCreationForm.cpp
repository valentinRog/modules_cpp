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

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    check_executability(executor);
    std::ofstream oFile;
    oFile.open((_target + "_shrubbery").c_str(), std::ios::out);
    oFile << "      ,.," << std::endl;
	oFile << "      MMMM_    ,..," << std::endl;
	oFile << "        \"_ \"__\"MMMMM          ,...,," << std::endl;
	oFile << " ,..., __.\" --\"    ,.,     _-\"MMMMMMM" << std::endl;
	oFile << "MMMMMM\"___ \"_._   MMM\"_.\"\" _ \"\"\"\"\"\"" << std::endl;
	oFile << " \"\"\"\"\"    \"\" , \\_.   \"_. .\"" << std::endl;
	oFile << "        ,., _\"__ \\__./ .\"" << std::endl;
	oFile << "       MMMMM_\"  \"_    ./" << std::endl;
	oFile << "        ''''      (    )" << std::endl;
	oFile << " ._______________.-'____\"---._." << std::endl;
	oFile << "  \\                          /" << std::endl;
	oFile << "   \\________________________/" << std::endl;
	oFile << "   (_)                    (_)" << std::endl;
}

/* -------------------------------------------------------------------------- */
