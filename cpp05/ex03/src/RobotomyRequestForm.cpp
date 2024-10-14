#include "RobotomyRequestForm.hpp"
#include "print.hpp"

RobotomyRequestForm::RobotomyRequestForm ()
    : AForm (72, 45, "RobotomyRequestForm"), _target ("Nobody")
{
}

RobotomyRequestForm::RobotomyRequestForm (std::string target)
    : AForm (72, 45, "RobotomyRequestForm"), _target (target)
{
}

RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm &other)
    : AForm (other), _target (other._target)
{
}

RobotomyRequestForm &
RobotomyRequestForm::operator= (const RobotomyRequestForm &other)
{
  this->AForm::operator= (other);
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm () {}

std::string
RobotomyRequestForm::getTarget () const
{
  return _target;
}

void
RobotomyRequestForm::execute (const Bureaucrat &executor) const
{
  static short calls_number = 1;

  if (!isSigned ())
    throw AForm::FormNotSignedException ();
  else if (executor.getGrade () > getExecGrade ())
    throw Bureaucrat::GradeTooLowException ();
  print ("Bzzzzzzzzzz");
  if (calls_number % 2)
    print (_target << " has been robotomized successfully.");
  else
    print (_target << " robotomization failed.");
  calls_number++;
}
