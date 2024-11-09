#include "BitcoinExchange.hpp"
#include "Defines.hpp"

#include <fstream>

int
main ()
{
  BitcoinExchange exchange;
  std::map<std::string, float> *data;
  try
    {
      data = exchange.loadDatabase ("cpp_09/data.csv");
      delete data;
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what () << '\n';
    }

}