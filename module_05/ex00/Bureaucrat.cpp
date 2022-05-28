#include "Bureaucrat.hpp"

/* -------------------------------------------------------------------------- */

int const Bureaucrat::_lowestGrade  = 150;
int const Bureaucrat::_highestGrade = 1;

/* -------------------------------------------------------------------------- */

Bureaucrat::Bureaucrat() : _grade( _lowestGrade ) {}

Bureaucrat::Bureaucrat( std::string const &name, int grade )
    : _name( name ),
      _grade( grade ) {
    check_grade();
}

Bureaucrat::Bureaucrat( Bureaucrat const &other )
    : _name( other._name ),
      _grade( other._grade ) {
    *this = other;
    check_grade();
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &other ) {
    _grade = other._grade;
    check_grade();
    return *this;
}

Bureaucrat::~Bureaucrat() {}

/* -------------------------------------------------------------------------- */

std::string const &Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

/* -------------------------------------------------------------------------- */

void Bureaucrat::promote() {
    _grade--;
    check_grade();
}

void Bureaucrat::demote() {
    _grade++;
    check_grade();
}

/* -------------------------------------------------------------------------- */

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "grade too low";
}

/* -------------------------------------------------------------------------- */

void Bureaucrat::check_grade() const {
    if ( _grade > _lowestGrade ) { throw GradeTooLowException(); }
    if ( _grade < _highestGrade ) { throw GradeTooHighException(); }
}

/* -------------------------------------------------------------------------- */

void Bureaucrat::print( std::ostream &os ) const {
    os << "{ ";
    os << "name: \"" << _name << "\", ";
    os << "grade: " << _grade;
    os << " }";
}

/* -------------------------------------------------------------------------- */

std::ostream &operator<<( std::ostream &os, Bureaucrat const &bureaucrat ) {
    bureaucrat.print( os );
    return os;
}

/* -------------------------------------------------------------------------- */
