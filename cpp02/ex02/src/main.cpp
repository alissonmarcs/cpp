#include <iostream>

#include "Fixed.hpp"

int main( void )
{
  Fixed a(42.42f);
  Fixed b(21.21f);

  std::cout << a / b << std::endl;
}
