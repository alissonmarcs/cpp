#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "print.hpp"

#include <iostream>

AForm::AForm ()
    : _name ("default"), _signGrade (150), _execGrade (150), _isSigned (false)
{
}

AForm::AForm (const AForm &other)
    : _name (other._name), _signGrade (other._signGrade),
      _execGrade (other._execGrade), _isSigned (other._isSigned)
{
}

AForm &
AForm::operator= (const AForm &other)
{
  this->_isSigned = other._isSigned;
  return *this;
}

AForm::~AForm () {}

std::string
AForm::getName () const
{
  return _name;
}

int
AForm::getSignGrade () const
{
  return _signGrade;
}

int
AForm::getExecGrade () const
{
  return _execGrade;
}

bool
AForm::isSigned () const
{
  return _isSigned;
}

void
AForm::beSigned (const Bureaucrat &bureaucrat)
{
  if (bureaucrat.getGrade () > _signGrade)
    throw Bureaucrat::GradeTooLowException ();
  _isSigned = true;
}

std::ostream &
operator<< (std::ostream &out, const AForm &object)
{
  out << "AForm: " << object.getName ()
      << ", sign grade: " << object.getSignGrade ()
      << ", exec grade: " << object.getExecGrade ()
      << ", signed: " << object.isSigned ();
  return out;
}

AForm::AForm (int signGrade, int execGrade, std::string name)
    : _name (name), _signGrade (signGrade), _execGrade (execGrade),
      _isSigned (false)
{
  if (signGrade < 1 || execGrade < 1)
    throw AForm::GradeTooHighException ();
  else if (signGrade > 150 || execGrade > 150)
    throw AForm::GradeTooLowException ();
}

const char *
AForm::GradeTooLowException::what () const throw ()
{
  return "Grade is too low";
}

const char *
AForm::GradeTooHighException::what () const throw ()
{
  return "Grade is too high";
}

const char *
AForm::FormNotSignedException::what () const throw ()
{
  return "Form is not signed";
}
