#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

Form::Form ()
    : _name ("default"), _signGrade (150), _execGrade (150), _isSigned (false)
{
}

Form::Form (const Form &other)
    : _name (other._name), _signGrade (other._signGrade),
      _execGrade (other._execGrade), _isSigned (other._isSigned)
{
  this->_isSigned = other._isSigned;
}

Form &
Form::operator= (const Form &other)
{
  this->_isSigned = other._isSigned;
  return *this;
}

Form::~Form () {}

std::string
Form::getName () const
{
  return _name;
}

int
Form::getSignGrade () const
{
  return _signGrade;
}

int
Form::getExecGrade () const
{
  return _execGrade;
}

bool
Form::isSigned () const
{
  return _isSigned;
}

void
Form::beSigned (const Bureaucrat &bureaucrat)
{
  if (bureaucrat.getGrade () > _signGrade)
    throw GradeTooLowException ();
  _isSigned = true;
}

std::ostream &
operator<< (std::ostream &out, const Form &object)
{
  out << "Form: " << object.getName ()
      << ", sign grade: " << object.getSignGrade ()
      << ", exec grade: " << object.getExecGrade ()
      << ", signed: " << object.isSigned ();
  return out;
}

Form::Form (int signGrade, int execGrade, std::string name)
    : _name (name), _signGrade (signGrade), _execGrade (execGrade),
      _isSigned (false)
{
  if (signGrade < 1 || execGrade < 1)
    throw GradeTooHighException ();
  else if (signGrade > 150 || execGrade > 150)
    throw GradeTooLowException ();
}

const char *
Form::GradeTooLowException::what () const throw ()
{
  return "Grade is too low";
}

const char *
Form::GradeTooHighException::what () const throw ()
{
  return "Grade is too high";
}
