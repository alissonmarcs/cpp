#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed () : _rawBits (0) {}

Fixed::Fixed (const int Value)
{
  this->_rawBits = Value << Fixed::_bitsOffset;
}

int
Fixed::toInt () const
{
  return this->_rawBits >> Fixed::_bitsOffset;
}

Fixed::Fixed (const float Value)
{
  this->_rawBits = roundf(Value * (1 << Fixed::_bitsOffset));
}

float
Fixed::toFloat () const
{
  return (float) this->_rawBits / (1 << Fixed::_bitsOffset);
}

bool
Fixed::operator>(const Fixed &object) const
{
  return this->toFloat() > object.toFloat();
}

bool
Fixed::operator>=(const Fixed &object) const
{
  return this->toFloat() >= object.toFloat();
}

bool
Fixed::operator<(const Fixed &object) const
{
  return this->toFloat() < object.toFloat();
}

bool
Fixed::operator<=(const Fixed &object) const
{
  return this->toFloat() <= object.toFloat();
}

bool
Fixed::operator==(const Fixed &object) const
{
  return this->toFloat() == object.toFloat();
}

bool
Fixed::operator!=(const Fixed &object) const
{
  return this->toFloat() != object.toFloat();
}

Fixed
Fixed::operator+(const Fixed &object) const
{
  return Fixed(this->toFloat() + object.toFloat());
}

Fixed
Fixed::operator-(const Fixed &object) const
{
  return Fixed(this->toFloat() - object.toFloat());
}

Fixed
Fixed::operator*(const Fixed &object) const
{
  return Fixed(this->toFloat() * object.toFloat());
}

Fixed
Fixed::operator/(const Fixed &object) const
{
  return Fixed(this->toFloat() / object.toFloat());
}

Fixed
Fixed::operator++(void) 
{
  this->setRawBits(this->getRawBits() + 1);
  return *this;
}

Fixed
Fixed::operator++(int)
{
  Fixed tmp(*this);

  this->setRawBits(this->getRawBits() + 1);
  return tmp;
}

Fixed
Fixed::operator--(void)
{
  this->setRawBits(this->getRawBits() - 1);
  return *this;
}

Fixed
Fixed::operator--(int)
{
  Fixed tmp(*this);

  this->setRawBits(this->getRawBits() - 1);
  return tmp;
}

Fixed &
Fixed::operator= (const Fixed &object)
{
  this->setRawBits(object.getRawBits());
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
  *this = object;
}

Fixed::~Fixed () {}

int
Fixed::getRawBits (void) const
{
  return _rawBits;
}

void
Fixed::setRawBits (const int bits)
{
  _rawBits = bits;
}

const Fixed &
Fixed::min(const Fixed &a, const Fixed &b)
{
  return (a < b) ? a : b;
}

const Fixed &
Fixed::max(const Fixed &a, const Fixed &b)
{
  return (a > b) ? a : b;
}
