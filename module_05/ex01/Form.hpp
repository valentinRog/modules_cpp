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
    ~Form();

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

    void check_grade() const;

    bool beSigned( Bureaucrat const &bureaucrat );

    void print( std::ostream &os ) const;
};

std::ostream &operator<<( std::ostream &os, Form const &form );

#endif