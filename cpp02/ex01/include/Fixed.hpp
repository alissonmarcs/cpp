#pragma once

#include <iosfwd>

class Fixed
{
public:
  Fixed ();
  ~Fixed ();
  Fixed (const Fixed &object);
  Fixed (const int Value);
  int toInt() const;
  Fixed (const float Value);
  float toFloat() const;
  Fixed &operator= (const Fixed &object);
  int getRawBits (void) const;
  void setRawBits (int const raw);

private:
  int _rawBits;
  const static int _bitsOffset = 8;
};

std::ostream&
operator<<(std::ostream &out, const Fixed &objec);
