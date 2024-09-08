#include "Brain.hpp"

Brain::Brain()
{
	printf("Brain default constructor called\n");

}

Brain::Brain(const Brain &other) 
{
	
}

Brain &
Brain::operator=(const Brain &other)
{
	return *this;
}

Brain::~Brain()
{
	printf("Brain destructor called\n");

}
