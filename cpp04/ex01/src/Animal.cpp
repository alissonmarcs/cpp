#include "Animal.hpp"
#include "print.hpp"

Animal::Animal () : _type ("Default animal")
{
  print ("Animal default constructor called");
}

Animal::Animal (const Animal &other)
{
  print ("Animal copy constructor called");
  this->_type = other._type;
}

Animal &
Animal::operator= (const Animal &other)
{
  this->_type = other._type;
  return *this;
}

Animal::~Animal () { print ("Animal destructor called"); }

void
Animal::makeSound () const
{
  print ("Animal sound");
}

std::string
Animal::getType () const
{
  return _type;
}

void
Animal::setType (std::string type)
{
  _type = type;
}
