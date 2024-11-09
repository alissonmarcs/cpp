#include "BitcoinExchange.hpp"
#include "Defines.hpp"

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

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

bool
BitcoinExchange::isDateValid(std::string date)
{
  const char *delimiter = "-";
  int tokenCount = 0, hifenCount = 0;
  char *token;

  for (size_t i = 0; i < date.size(); i++)
    {
      if (date[i] == '-')
        hifenCount++;
    }
  if (hifenCount != 2)
    return false;
  token = std::strtok(const_cast<char*>(date.c_str()), delimiter);
  while (token != 0)
    {
      if (tokenCount == 0 && (std::atoi(token) < 0 || std::atoi(token) > 2024))
        return false;
      if (tokenCount == 1 && (std::atoi(token) < 1 || std::atoi(token) > 12))
        return false;
      if (tokenCount == 2 && (std::atoi(token) < 1 || std::atoi(token) > 31))
        return false;
      tokenCount++;
      token = std::strtok(0, delimiter);
    }
  if (tokenCount != 3)
    return false;
  return true;
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
  if (isDateValid (line.substr (0, i)) == false && lineNumber != 1)
    {
      error += "invalid date";
      throw std::runtime_error (error.c_str ());
    }
}

void
BitcoinExchange::loadDatabase (std::string filename)
{
  std::ifstream file (filename.c_str ());
  std::string line;

  if (file.is_open ())
    {
      size_t i, lineNumber = 1;
      while (std::getline (file, line))
        {
          validadeDatabaseLine(line, lineNumber);
          i = line.find (",");
          if (i != std::string::npos)
            {
              std::string key = line.substr (0, i);
              float value = std::atof (line.substr (i + 1).c_str ());
             _Database[key] = value;
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
}