#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "print.hpp"

Bureaucrat::Bureaucrat () : _name ("Nobody"), _grade (1) {}

Bureaucrat::Bureaucrat (const Bureaucrat &other)
    : _name (other._name), _grade (other._grade)
{
}

Bureaucrat &
Bureaucrat::operator= (const Bureaucrat &other)
{
  if (this != &other)
    this->_grade = other._grade;
  return *this;
}

Bureaucrat::~Bureaucrat () {}

std::string
Bureaucrat::getName () const
{
  return _name;
}

short
Bureaucrat::getGrade () const
{
  return _grade;
}

Bureaucrat::Bureaucrat (std::string name, short grade)
    : _name (name), _grade (grade)
{
  if (grade < 1)
    throw GradeTooHighException ();
  else if (grade > 150)
    throw GradeTooLowException ();
}

void
Bureaucrat::incrementGrade ()
{
  if (_grade == 1)
    throw GradeTooHighException ();
  _grade--;
}

void
Bureaucrat::decrementGrade ()
{
  if (_grade == 150)
    throw GradeTooLowException ();
  _grade++;
}

std::ostream &
operator<< (std::ostream &out, const Bureaucrat &obj)
{
  out << "Bureaucrat " << obj.getName () << " has the grade "
      << obj.getGrade ();
  return out;
}

void
Bureaucrat::signForm (AForm &form)
{
  try
    {
      form.beSigned (*this);
      print ("Bureaucrat " << _name << " signs " << form.getName ());
    }
  catch (AForm::GradeTooLowException &e)
    {
      print ("Bureaucrat " << _name << " cannot sign " << form.getName ()
                           << " because his grade is too low");
    }
}

void
Bureaucrat::executeForm (AForm const &form)
{
  try
  {
     form.execute (*this);
  }
  catch (const std::exception &e)
  {
      print(e.what());
  }
}

const char *
Bureaucrat::GradeTooLowException::what () const throw ()
{
  return "Grade is too low";
}

const char *
Bureaucrat::GradeTooHighException::what () const throw ()
{
  return "Grade is too high";
}
