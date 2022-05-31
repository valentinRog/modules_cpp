#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

private:
    static int const         _formCount;
    static std::string const _formStr[];

    enum _formType {
        SHRUBBERY_CREATION,
        ROBOTOMY_REQUEST,
        PRESIDENTIAL_PARDON
    };

    static int _get_index( std::string const &name );

public:
    Intern();
    Intern( Intern const &other );
    Intern &operator=( Intern const &other );
    ~Intern();

	class FormNotFoundException : public std::exception {
        virtual const char *what() const throw();
    };

    Form *makeForm( std::string const &name, std::string const &target ) const;
};

#endif
