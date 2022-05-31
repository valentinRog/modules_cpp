#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

    Intern intern;

    try {
        Form *form = intern.makeForm( "shrubbery creation", "target" );
        delete form;
    } catch ( const std::exception &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Form *form = intern.makeForm( "robotomy request", "target" );
        delete form;
    } catch ( const std::exception &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Form *form = intern.makeForm( "presidential pardon", "target" );
        delete form;
    } catch ( const std::exception &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Form *form = intern.makeForm( "yo", "target" );
        delete form;
    } catch ( const std::exception &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}