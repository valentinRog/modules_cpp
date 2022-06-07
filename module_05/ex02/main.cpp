#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    std::srand( time( 0 ) );

    Bureaucrat b1( "b1", 1 );
    Bureaucrat b2( "b2", 40 );
    Bureaucrat b3( "b3", 150 );

    try {
        Form *form = new ShrubberyCreationForm( "Target1" );
        form->beSigned( b2 );
        form->execute( b2 );
        delete form;
    } catch ( std::exception &e ) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        Form *form = new PresidentialPardonForm( "Target2" );
        form->beSigned( b1 );
        form->execute( b1 );
        delete form;
    } catch ( std::exception &e ) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        Form *form = new RobotomyRequestForm( "Target3" );
        form->beSigned( b2 );
        form->execute( b1 );
        form->execute( b1 );
        form->execute( b1 );
        form->execute( b1 );
        delete form;
    } catch ( std::exception &e ) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    {
        PresidentialPardonForm f1("Target");
        b2.signForm(f1);
        b1.executeForm(f1);
        b1.signForm(f1);
        b3.executeForm(f1);
        b1.executeForm(f1);
        std::cout << std::endl;
    }

    return 0;
}