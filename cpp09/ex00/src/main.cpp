#include "BitcoinExchange.hpp"
#include "Defines.hpp"

#include <fstream>
#include <iomanip>

int
main (int argc, char **argv)
{
  try
    {
      BitcoinExchange exchange (argc, argv);
    }
  catch (std::exception &e)
    {
      std::cout << RED "Error: " RESET << e.what () << std::endl;
    }
}