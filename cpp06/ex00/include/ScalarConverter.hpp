#pragma once

#include <cstdlib>
#include <exception>
#include <string>

class ScalarConverter
{
private:
  ScalarConverter ();
  ScalarConverter (const ScalarConverter &other);
  ScalarConverter &operator= (const ScalarConverter &other);
  ~ScalarConverter ();

public:
  static void convert (std::string str);
};
