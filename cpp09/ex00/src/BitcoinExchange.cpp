#include "BitcoinExchange.hpp"
#include "Defines.hpp"

#include <fstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange () {}

BitcoinExchange::BitcoinExchange (const BitcoinExchange &other)
{
  (void)other;
}

BitcoinExchange &
BitcoinExchange::operator= (const BitcoinExchange &other)
{
  (void)other;
  return *this;
}

BitcoinExchange::~BitcoinExchange () {}

std::map<std::string, float> *
BitcoinExchange::loadDatabase (std::string filename)
{
  std::ifstream file (filename.c_str ());
  std::string line;
  std::map<std::string, float> *data;

  if (file.is_open ())
    {
      size_t i;
      data = new std::map<std::string, float>;
      while (std::getline (file, line))
        {
          i = line.find (",");
          if (i != std::string::npos)
            {
              std::string key = line.substr (0, i);
              float value = std::atof (line.substr (i + 1).c_str ());
              (*data)[key] = value;
            }
        }
      file.close ();
    }
  else
    {
      std::string error
          = RED "Error:" RESET " unable to open \'" + filename + "\' file";
      throw std::runtime_error (error.c_str ());
    }
  return data;
}