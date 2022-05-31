#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {

private:
    static int const _gradeToSign;
    static int const _gradeToExecute;

    std::string const _target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm( std::string const &target );
	ShrubberyCreationForm( ShrubberyCreationForm const &other );
    ShrubberyCreationForm &operator=( const ShrubberyCreationForm &other );
    ~ShrubberyCreationForm( void );
};

#endif
