#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {

private:
    static int const _gradeToSign;
    static int const _gradeToExecute;

    std::string const _target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm( std::string const &target );
	PresidentialPardonForm( PresidentialPardonForm const &other );
    PresidentialPardonForm &operator=( const PresidentialPardonForm &other );
    ~PresidentialPardonForm( void );

    void execute(Bureaucrat const & executor) const;
};

#endif
