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

  it = exchange.getNearestDate ("2017-03-12");
  std::cout << "end()" << (it == exchange._Database.end ()) << std::endl;
  std::cout << "begin()" << (it == exchange._Database.begin ()) << std::endl;
}