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
incrementGradeFail ()
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
decrementGradeFail ()
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
incrementGradeSucess ()
{
  Bureaucrat b ("Thor", 149);

  try
    {
      b.incrementGrade ();
      print ("Grade: " << b.getGrade ());
    }
  catch (const std::exception &e)
    {
      print (e.what ());
    }
}

void
decrementGradeSucess ()
{
  Bureaucrat b ("Thor", 149);

  try
    {
      b.decrementGrade ();
      print ("Grade: " << b.getGrade ());
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
  Tests::incrementGradeFail ();
  print (GREEN TITTLE "Low exception when decrement" RESET);
  Tests::decrementGradeFail ();
  print (GREEN TITTLE "Overload of print operator" RESET);
  Tests::printOperator ();
  print (GREEN TITTLE "Increment Grade Success" RESET);
  Tests::incrementGradeSucess ();
  print (GREEN TITTLE "Decrement Grade Success" RESET);
  Tests::decrementGradeSucess ();
  return 0;
}
