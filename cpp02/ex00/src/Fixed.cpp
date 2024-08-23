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

Fixed::~Fixed() {}

int		Fixed::getRawBits(void) const
{
	std::cout << "Destructor called" << std::endl;
	return integer;
}

void	Fixed::setRawBits(const int bits)
{
	integer = bits;
}
