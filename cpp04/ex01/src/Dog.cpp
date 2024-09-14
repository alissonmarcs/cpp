#include "Dog.hpp"
#include "print.hpp"

Dog::Dog () : Animal ()
{
  print ("Dog default constructor called");
  this->_type = "Dog";
  this->brain = new Brain ();
}

Dog::Dog (const Dog &other) : Animal (other)
{
  print ("Dog copy constructor called");
  this->brain = new Brain ();
  *(this->brain) = *(other.brain);
}

Dog &
Dog::operator= (const Dog &other)
{
  print ("Dog assiment operator called");
  if (this != &other)
    *(this->brain) = *(other.brain);
  return *this;
}

Dog::~Dog ()
{
  print ("Dog destructor called");
  delete this->brain;
}

void
Dog::makeSound () const
{
  print ("Dog sound");
}

Brain *
Dog::getBrain () const
{
  return this->brain;
}
