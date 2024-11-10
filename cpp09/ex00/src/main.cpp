#include "BitcoinExchange.hpp"
#include "Defines.hpp"

#include <fstream>
#include <iomanip>

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

    std::map<std::string, double>::iterator it;

    it = exchange.getNearestDate("2022-03-24");
    print (it->first << ":" << std::fixed << std::setprecision (2) << it->second);
}