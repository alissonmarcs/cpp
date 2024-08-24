#pragma once

class Fixed
{
public:
  Fixed ();
  Fixed (const Fixed &object);
  ~Fixed ();
  Fixed &operator= (const Fixed &object);
  int getRawBits (void) const;
  void setRawBits (int const raw);

private:
  int integer;
  const static int _bits = 8;
};
