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

  std::map<std::string, float>::iterator it;

  it = exchange.getNearestDate ("2022-01-24");
  print ((it == exchange._Database.end ()) );
  // print (it->first << ":" << it->second);
}