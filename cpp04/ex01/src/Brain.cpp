#include "Brain.hpp"
#include "print.hpp"

Brain::Brain()
{
	print ("Brain default constructor called");
}

Brain::Brain(const Brain &other) 
{
	print ("Brain copy constructor called");
	*this = other;
}

Brain &
Brain::operator=(const Brain &other)
{
	print ("Brain assiment operator called");
	return *this;
}

Brain::~Brain()
{
	print ("Brain destructor called");
}

