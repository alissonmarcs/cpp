#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): integer(0)
{
	std::cout << "Dafault constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& object)
{
	*this = object;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &object)
{
	if (this != &object)
		this->integer = object.integer;
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "Destructor called" << std::endl;
	return integer;
}

void	Fixed::setRawBits(const int bits)
{
	integer = bits;
}
