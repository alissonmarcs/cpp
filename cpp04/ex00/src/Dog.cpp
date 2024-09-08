#include "Dog.hpp"

Dog::Dog() : Animal()
{
	print ("Dog constructor called");
	this->_type = "Dog";
}

Dog::Dog(const Dog &other) 
{
	print ("Dog copy constructor called");
	this->_type = other._type;
}

Dog &
Dog::operator=(const Dog &other)
{
	this->_type = other._type;
	return *this;
}

Dog::~Dog() {}

void
Dog::makeSound() const
{
	print ("Dog sound");
}
