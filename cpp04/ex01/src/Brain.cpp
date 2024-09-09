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
	print ("Brain assigment operator called");
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	print ("Brain destructor called");
}

void
Brain::setIdea(const std::string &idea, int index)
{
	if (index < 0 || index >= 100)
	{
		print ("Index out of range");
		return;
	}
	this->_ideas[index] = idea;
}

std::string
Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
	{
		print ("Index out of range");
		return "";
	}
	return this->_ideas[index];
}
