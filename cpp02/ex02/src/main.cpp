#include <iostream>

#include "Fixed.hpp"

int main( void )
{
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
  Fixed tmp(0);
  Fixed tmp2(b / tmp);

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max( a, b ) << std::endl;
  std::cout << tmp2.toInt() << std::endl;
  std::cout << tmp2.toFloat() << std::endl;

  return 0;
}
