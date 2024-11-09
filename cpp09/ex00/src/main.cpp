#include "BitcoinExchange.hpp"
#include "Defines.hpp"

#include <fstream>

int
main ()
{
  BitcoinExchange exchange;
  try
    {
      exchange.loadDatabase ("cpp_09/data.csv");
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what () << '\n';
    }
}