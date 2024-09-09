#include "Dog.hpp"
#include "print.hpp"

Dog::Dog () : Animal ()
{
  print ("Dog default constructor called");
  this->_type = "Dog";
}

Dog::Dog (const Dog &other) : Animal (other)
{
  print ("Dog copy constructor called");
  this->_type = other._type;
}

Dog &
Dog::operator= (const Dog &other)
{
  this->_type = other._type;
  return *this;
}

Dog::~Dog () { print ("Dog destructor called"); }

void
Dog::makeSound () const
{
  print ("Dog sound");
}
