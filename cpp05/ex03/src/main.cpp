#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "print.hpp"

namespace Tests
{
void
basic_tests ()
{
  Intern Intern;
  Bureaucrat batman ("batman", 1);
  AForm *form;

  form = Intern.makeForm ("presidential pardon", "target");
  form->beSigned (batman);
  form->execute (batman);

  delete form;

  form = Intern.makeForm ("robotomy request", "target");
  form->beSigned (batman);
  form->execute (batman);
  delete form;

  form = Intern.makeForm ("shrubbery creation", "target");
  form->beSigned (batman);
  form->execute (batman);
  delete form;
}

void
exceptions_tests ()
{
  Intern Intern;
  Bureaucrat batman ("batman", 1);
  AForm *form;

  try
    {
      form = Intern.makeForm ("nope", "target");
    }
  catch (std::exception &e)
    {
      print (e.what ());
    }
}
}

int
main (void)
{
  Tests::basic_tests ();
  Tests::exceptions_tests ();
  return 0;
}
