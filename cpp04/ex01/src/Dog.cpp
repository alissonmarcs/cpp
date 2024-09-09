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
  print ("pointer before: " << this->brain);
  this->brain = other.brain;
  print ("pointer after: " << this->brain);
}

Dog &
Dog::operator= (const Dog &other)
{
  print ("Dog assiment operator called");
  if (this != &other)
    {
      for (int i = 0; i < 100; i++)
        this->brain->setIdea (other.brain->getIdea (i), i);
    }
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
