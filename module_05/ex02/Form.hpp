#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
    static int const _lowestGrade;
    static int const _highestGrade;

    std::string const _name;
    bool              _signed;
    int const         _gradeToSign;
    int const         _gradeToExecute;

public:
    Form();
    Form( std::string const &name,
          int                gradeToSign    = _lowestGrade,
          int                gradeToExecute = _lowestGrade );
    Form( Form const &other );
    Form &operator=( Form const &other );
    virtual ~Form();

    std::string const &getName() const;
    bool               getSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;

    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };
    class NotSignedException : public std::exception {
        virtual const char *what() const throw();
    };

    void check_grade() const;

    void beSigned( Bureaucrat const &bureaucrat );

    void check_executability( Bureaucrat const &executor ) const;

    virtual void execute( Bureaucrat const &executor ) const = 0;

    virtual void print( std::ostream &os ) const;
};

std::ostream &operator<<( std::ostream &os, Form const &form );

#endif
