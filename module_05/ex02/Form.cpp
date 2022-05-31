#include "Form.hpp"

/* -------------------------------------------------------------------------- */

int const Form::_lowestGrade  = 150;
int const Form::_highestGrade = 1;

/* -------------------------------------------------------------------------- */

Form::Form()
    : _signed( false ),
      _gradeToSign( Bureaucrat::getLowestGrade() ),
      _gradeToExecute( Bureaucrat::getLowestGrade() ) {
    check_grade();
}

Form::Form( std::string const &name, int gradeToSign, int gradeToExecute )
    : _name( name ),
      _signed( false ),
      _gradeToSign( gradeToSign ),
      _gradeToExecute( gradeToExecute ) {
    check_grade();
}

Form::Form( Form const &other )
    : _name( other._name ),
      _gradeToSign( other._gradeToSign ),
      _gradeToExecute( other._gradeToExecute ) {
    *this = other;
    check_grade();
}

Form &Form::operator=( Form const &other ) {
    _signed = other._signed;
    return *this;
}

Form::~Form() {}

/* -------------------------------------------------------------------------- */

std::string const &Form::getName() const { return _name; }

bool Form::getSigned() const { return _signed; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExecute() const { return _gradeToExecute; }

/* -------------------------------------------------------------------------- */

const char *Form::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "grade too low";
}

const char *Form::NotSignedException::what() const throw() {
    return "not signed";
}

/* -------------------------------------------------------------------------- */

void Form::check_grade() const {
    if ( _gradeToSign > _lowestGrade || _gradeToExecute > _lowestGrade ) {
        throw GradeTooLowException();
    }
    if ( _gradeToSign < _highestGrade || _gradeToExecute < _highestGrade ) {
        throw GradeTooHighException();
    }
}

/* -------------------------------------------------------------------------- */

void Form::beSigned( Bureaucrat const &bureaucrat ) {
    if ( bureaucrat.getGrade() <= _gradeToSign ) {
        _signed = true;
    } else {
        throw GradeTooLowException();
    }
}

/* -------------------------------------------------------------------------- */

void Form::check_executability( Bureaucrat const &executor ) const {
    if ( !_signed ) { throw NotSignedException(); }
    if ( executor.getGrade() > _gradeToExecute ) {
        throw GradeTooLowException();
    }
}

/* -------------------------------------------------------------------------- */

void Form::print( std::ostream &os ) const {
    os << "{ ";
    os << "name: \"" << _name << "\", ";
    os << "signed: " << _signed << ", ";
    os << "gradeToSign: " << _gradeToSign<< ", ";
    os << "gradeToExecute: " << _gradeToExecute;
    os << " }";
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, Form const &form ) {
    form.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
