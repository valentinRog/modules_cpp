#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat {

private:
    static int const _lowestGrade;
    static int const _highestGrade;

    std::string const _name;
    int               _grade;

public:
    Bureaucrat();
    Bureaucrat( std::string const &name, int grade = _lowestGrade );
    Bureaucrat( Bureaucrat const &other );
    Bureaucrat &operator=( Bureaucrat const &other );
    ~Bureaucrat();

    static int getLowestGrade();
    static int getHighestGrade();

    std::string const &getName() const;
    int                getGrade() const;

    void promote();
    void demote();

    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };

    void check_grade() const;

    bool signForm( Form &form ) const;

    void print( std::ostream &os ) const;
};

std::ostream &operator<<( std::ostream &os, Bureaucrat const &bureaucrat );

#endif
