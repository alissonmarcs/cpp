#include "Cat.hpp"
#include "print.hpp"

Cat::Cat () : Animal ()
{
  print ("Cat default constructor called");
  this->_type = "Cat";
  this->brain = new Brain ();
}

Cat::Cat (const Cat &other) : Animal (other)
{
  print ("Cat copy constructor called");
  this->brain = new Brain ();
  *(this->brain) = *(other.brain);
}

Cat &
Cat::operator= (const Cat &other)
{
  print ("Cat assigment operator called");
  if (this != &other)
    *(this->brain) = *(other.brain);
  return *this;
}

Cat::~Cat ()
{
  print ("Cat destructor called");
  delete this->brain;
}

void
Cat::makeSound () const
{
  print ("Cat sound");
}

Brain *
Cat::getBrain () const
{
  return this->brain;
}
