#include "BitcoinExchange.hpp"
#include "Defines.hpp"

int
main ()
{
  BitcoinExchange exchange;
  std::map<std::string, float> *data;
  try
    {
      data = exchange.loadDatabase ("data.csv");
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what () << '\n';
    }
  std::cout << "size(): " << data->size () << std::endl;
  delete data;
}