#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form {

private:
    static int const _gradeToSign;
    static int const _gradeToExecute;

    std::string const _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm( std::string const &target );
	RobotomyRequestForm( RobotomyRequestForm const &other );
    RobotomyRequestForm &operator=( const RobotomyRequestForm &other );
    ~RobotomyRequestForm( void );

    void execute(Bureaucrat const & executor) const;

    void print( std::ostream &os ) const;
};

#endif
