#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "print.hpp"

namespace Tests
{
void
signForm ()
{
  Bureaucrat man ("man", 100);
  Form job (42, 90, "job");
  man.signForm (job);

  Bureaucrat woman ("woman", 30);
  Form car (40, 89, "car");
  woman.signForm (car);
}

void
beSigned ()
{
  Bureaucrat man ("man", 100);
  Form motocycle (42, 90, "motocycle");

  try
    {
      motocycle.beSigned (man);
    }
  catch (const std::exception &e)
    {
      print (e.what ());
    }
}

void
formExceptions ()
{
  try
    {
      Form highExecGrade (0, 100, "TestForm");
    }
  catch (const std::exception &e)
    {
      print (e.what ());
    }
  try
    {
      Form lowExecGrade (200, 100, "TestForm");
    }
  catch (const std::exception &e)
    {
      print (e.what ());
    }
  try
    {
      Form highSignGrade (100, 0, "TestForm");
    }
  catch (const std::exception &e)
    {
      print (e.what ());
    }
  try
    {
      Form lowSignGrade (100, 200, "TestForm");
    }
  catch (const std::exception &e)
    {
      print (e.what ());
    }
}

void
overloarInsertion ()
{
  Bureaucrat spiderMan ("spiderMan", 41);
  Form web (42, 90, "web");

  spiderMan.signForm (web);
  std::cout << web << std::endl;
}

void
getters ()
{
  Form dog (3, 90, "Dog");

  print ("Name: " << dog.getName ());
  print ("Sign grade " << dog.getSignGrade ());
  print ("Exec grade " << dog.getExecGrade ());
  print ("Bool if is signed: " << dog.isSigned ());
}
}

int
main (void)
{
  print (GREEN TITTLE "Getters" RESET);
  Tests::getters ();
  print (GREEN TITTLE "Bureaucrat try to sign a form" RESET);
  Tests::signForm ();
  print (GREEN TITTLE "beSigned()" RESET);
  Tests::beSigned ();
  print (GREEN TITTLE "Form constructor exceptions" RESET);
  Tests::formExceptions ();
  print (GREEN TITTLE "Overload of insertion" RESET);
  Tests::overloarInsertion ();
}
