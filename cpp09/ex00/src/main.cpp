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
  catch (const std::exception &e)
    {
      std::cerr << e.what () << '\n';
    }
}