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
  Fixed operator++(void);
  Fixed operator++(int);
  Fixed operator--(void);
  Fixed operator--(int);
  bool  operator>(const Fixed &object) const;
  bool  operator<(const Fixed &object) const;
  bool  operator>=(const Fixed &object) const;
  bool  operator<=(const Fixed &object) const;
  bool  operator==(const Fixed &object) const;
  bool  operator!=(const Fixed &object) const;
  Fixed operator+(const Fixed &object) const;
  Fixed operator-(const Fixed &object) const;
  Fixed operator*(const Fixed &object) const;
  Fixed operator/(const Fixed &object) const;
  int getRawBits (void) const;
  void setRawBits (int const raw);
  static Fixed & min(Fixed &a, Fixed &b);

private:
  int _rawBits;
  const static int _bitsOffset = 8;
};

std::ostream&
operator<<(std::ostream &out, const Fixed &objec);
