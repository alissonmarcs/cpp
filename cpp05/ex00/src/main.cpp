#include "Bureaucrat.hpp"
#include "print.hpp"

namespace Tests
{
void
defaultConstructor ()
{
  Bureaucrat b1;

  print ("Name: " << b1.getName ());
  print ("Grade: " << b1.getGrade ());
}

void
tooHigh ()
{
  try
    {
      Bureaucrat b ("Mister", 0);
    }
  catch (const std::exception &e)
    {
      print (e.what ());
    }
}

void
tooLow ()
{
  try
    {
      Bureaucrat b ("Melvin", 200);
    }
  catch (const std::exception &e)
    {
      print (e.what ());
    }
}

void
incrementGrade ()
{
  Bureaucrat b ("Alisson", 1);

  try
    {
      b.incrementGrade ();
    }
  catch (const std::exception &e)
    {
      print (e.what ());
    }
}

void
decrementGrade ()
{
  Bureaucrat b ("Thor", 150);

  try
    {
      b.decrementGrade ();
    }
  catch (const std::exception &e)
    {
      print (e.what ());
    }
}

void
printOperator ()
{
  Bureaucrat b ("Batman", 100);

  std::cout << b << std::endl;
}
}

int
main (void)
{
  print (GREEN TITTLE "Default constructor" RESET);
  Tests::defaultConstructor ();
  print (GREEN TITTLE "High exception in constructor" RESET);
  Tests::tooHigh ();
  print (GREEN TITTLE "Low exception in constructor" RESET);
  Tests::tooLow ();
  print (GREEN TITTLE "High exception when increment" RESET);
  Tests::incrementGrade ();
  print (GREEN TITTLE "Low exception when decrement" RESET);
  Tests::decrementGrade ();
  print (GREEN TITTLE "Overload of print operator" RESET);
  Tests::printOperator ();

  return 0;
}
