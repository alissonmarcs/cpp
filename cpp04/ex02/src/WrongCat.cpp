#include "WrongCat.hpp"
#include "print.hpp"

WrongCat::WrongCat () : WrongAnimal ()
{
  print ("WrongCat default constructor");
}

WrongCat::WrongCat (const WrongCat &other) : WrongAnimal (other)
{
  (void)other;
  print ("WrongCat copy constructor");
  return;
}

void
WrongCat::operator= (const WrongCat &other)
{
  (void)other;
  print ("WrongCat assignment operator");
  return;
}

WrongCat::~WrongCat () { print ("WrongCat destructor"); }
