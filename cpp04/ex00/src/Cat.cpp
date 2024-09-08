#include "Cat.hpp"

Cat::Cat() : Animal()
{
	print ("Cat default constructor called");
	this->_type = "Cat";
}

Cat::Cat(const Cat &other)
{
	print ("Cat copy constructor called");
	this->_type = other._type;
}

Cat &
Cat::operator=(const Cat &other)
{
	this->_type = other._type;
	return *this;
}

Cat::~Cat() { print ("Cat destructor called"); }

void
Cat::makeSound() const
{
	print ("Cat sound");
}
