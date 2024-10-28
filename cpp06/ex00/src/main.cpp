#include "Helpers.hpp"
#include "ScalarConverter.hpp"
#include "defines.hpp"

int
main (int argc, char **argv)
{
  if (argc != 2)
    {
      print (RED "Error: " RESET "Usage: ./ex00 [string]");
      return 1;
    }
  else if (!Helpers::validade_string (argv[1]))
    {
      print (RED "Error: " RESET "Invalid string");
      return 1;
    }
  ScalarConverter::convert (argv[1]); 
  return 0;
}
    