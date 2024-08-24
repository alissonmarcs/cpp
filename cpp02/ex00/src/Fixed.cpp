#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): integer(0)
{
	std::cout << "Dafault constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &object)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &object)
		integer = object.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed& object)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = object;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return integer;
}

void	Fixed::setRawBits(const int bits)
{
	std::cout << "setRawBits member function called" << std::endl;
	integer = bits;
}
