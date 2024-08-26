#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed () : _rawBits (0)
{
  std::cout << "Dafault constructor called" << std::endl;
}

Fixed::Fixed (const int Value)
{
  std::cout << "Int constructor called" << std::endl;
  this->_rawBits = Value << Fixed::_bitsOffset;
}

int
Fixed::toInt () const
{
  return this->_rawBits >> Fixed::_bitsOffset;
}

Fixed::Fixed (const float Value)
{
  std::cout << "Float constructor called" << std::endl;
  this->_rawBits = roundf(Value * (1 << Fixed::_bitsOffset));
}

float
Fixed::toFloat () const
{
  return (float) this->_rawBits / (1 << Fixed::_bitsOffset);
}

Fixed &
Fixed::operator= (const Fixed &object)
{
  std::cout << "Copy assigment operator called" << std::endl;
  if (this != &object)
    _rawBits = object.getRawBits ();
  return *this;
}

std::ostream &
operator<<(std::ostream &out, const Fixed &object)
{
  out << object.toFloat();
  return out;
}

Fixed::Fixed (const Fixed &object)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = object;
}

Fixed::~Fixed () { std::cout << "Destructor called" << std::endl; }

int
Fixed::getRawBits (void) const
{
  std::cout << "getRawBits member function called" << std::endl;
  return _rawBits;
}

void
Fixed::setRawBits (const int bits)
{
  std::cout << "setRawBits member function called" << std::endl;
  _rawBits = bits;
}
