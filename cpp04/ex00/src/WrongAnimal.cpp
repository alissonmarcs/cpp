#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
	print ("WrongAnimal default constructor called");
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) 
{
	(void)other;
	print ("WrongAnimal copy constructor called");
	return ;
}

void
WrongAnimal::operator=(const WrongAnimal &other)
{
	(void)other;
	print ("WrongAnimal assignment operator called");
	return ;
}

WrongAnimal::~WrongAnimal()
{
	print ("WrongAnimal destructor called");
}

void
WrongAnimal::makeSound() const
{
	print ("WrongAnimal sound");
}
