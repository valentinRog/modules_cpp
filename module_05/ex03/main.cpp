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
        std::cout << *form << std::endl;
        delete form;
    } catch ( const std::exception &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Form *form = intern.makeForm( "robotomy request", "target" );
        std::cout << *form << std::endl;
        delete form;
    } catch ( const std::exception &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Form *form = intern.makeForm( "presidential pardon", "target" );
        std::cout << *form << std::endl;
        delete form;
    } catch ( const std::exception &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Form *form = intern.makeForm( "yo", "target" );
        std::cout << *form << std::endl;
        delete form;
    } catch ( const std::exception &e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
