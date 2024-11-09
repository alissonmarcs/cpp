#include "BitcoinExchange.hpp"
#include "Defines.hpp"

#include <cstdlib>
#include <fstream>
#include <sstream>

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

bool
BitcoinExchange::haveAplha (std::string str)
{
  for (size_t i = 0; i < str.size (); i++)
    {
      if (std::isalpha (str[i]))
        return true;
    }
  return false;
}

void
BitcoinExchange::validadeDatabaseLine(std::string line, size_t lineNumber)
{
  size_t i;
  std::string error = RED "Database error: " RESET "line: ";
  std::stringstream lineNumberStr;

  lineNumberStr << lineNumber;
  error += lineNumberStr.str() + ": ";
  i = line.find (",");
  if (line.empty ())
    {
      error += "empty line";
      throw std::runtime_error (error.c_str ());
    }
  if (i == std::string::npos)
    {
      error += "expected ','";
      throw std::runtime_error (error.c_str ());
    }
  if (haveAplha (line.substr (0, i)) && lineNumber != 1)
    {
      error += "expected only numbers";
      throw std::runtime_error (error.c_str ());
    }
}

std::map<std::string, float> *
BitcoinExchange::loadDatabase (std::string filename)
{
  std::ifstream file (filename.c_str ());
  std::string line;
  std::map<std::string, float> *data;

  if (file.is_open ())
    {
      size_t i, lineNumber = 1;
      data = new std::map<std::string, float>;
      while (std::getline (file, line))
        {
          validadeDatabaseLine(line, lineNumber);
          i = line.find (",");
          if (i != std::string::npos)
            {
              std::string key = line.substr (0, i);
              float value = std::atof (line.substr (i + 1).c_str ());
              (*data)[key] = value;
            }
            lineNumber++;
        }
      file.close ();
    }
  else
    {
      std::string error
          = RED "Error:" RESET " unable to open '" + filename + "' file";
      throw std::runtime_error (error.c_str ());
    }
  return data;
}