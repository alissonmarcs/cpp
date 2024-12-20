#include "Defines.hpp"
#include "RPN.hpp"

int
main (int argc, char **argv)
{
  try
    {
      if (argc != 2 || (argv[1][0] == '\0'))
        throw std::invalid_argument ("Usage: ./RPN \"expression\"");
      RPN rpn (argv[1]);
    }
  catch (const std::exception &e)
    {
      std::cerr << RED "Error: " RESET << e.what () << std::endl;
      return 1;
    }
  return 0;
}