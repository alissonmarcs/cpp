#include "BitcoinExchange.hpp"
#include "Defines.hpp"

#include <fstream>

int
main ()
{
  BitcoinExchange exchange;
  std::map<std::string, float> *data = 0;
  try
    {
      data = exchange.loadDatabase ("cpp_09/data.csv");
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what () << '\n';
      delete data;
    }
}