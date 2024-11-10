#include "BitcoinExchange.hpp"
#include "Defines.hpp"

#include <fstream>
#include <iomanip>

int
main (int argc, char **argv)
{
  std::ifstream file (argv[1]);
  std::string line;

  while (std::getline (file, line))
    {
      try
        {
          BitcoinExchange::validadeInputLine (line);
          print (line << " => " << "OK");

        }
      catch (std::runtime_error &e)
        {
          print ("Error: " << e.what() << " => '" << line << "'");
        }
    }
}