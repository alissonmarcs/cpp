#include "BitcoinExchange.hpp"
#include "Defines.hpp"

#include <bits/stdc++.h>
#include <cstdlib>
#include <fstream>
#include <sstream>

void BitcoinExchange::validadeInputLine(std::string line)
{
  size_t i;

  if (line.empty())
    throw std::runtime_error("empty line"); 
  i = line.find("|");
  if (i == std::string::npos)
    throw std::runtime_error("expected '|'");
  std::string date = line.substr(0, i);
  trim (date);
  if (date.empty() || isDateValid(date) == false)
    throw std::runtime_error("invalid date");
  std::string value = line.substr(i + 1);
  trim (value);
  if (value.empty())
    throw std::runtime_error("empty value");
  if (std::atof(value.c_str()) < 0 || std::atof(value.c_str()) > 1000)
    throw std::runtime_error("invalid value");
}

BitcoinExchange::BitcoinExchange (int argc, char **argv)
{
  if (argc != 2)
      throw std::runtime_error ("invalid number of arguments");
  std::ifstream file (argv[1]);
  if (file.is_open () == false)
      throw std::runtime_error ("unable to open input file");
  loadDatabase ("cpp_09/data.csv");
}

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

std::map<std::string, double>::iterator
BitcoinExchange::getNearestDate (std::string inputDate)
{
  std::map<std::string, double>::iterator it;

  it = _Database.find (inputDate);
  if (it != _Database.end ())
    return it;
  it = _Database.lower_bound (inputDate);
  it--;
  return it;
}

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
BitcoinExchange::isValueValid (std::string value)
{
  if (value.empty ())
    return false;
  if (std::atof (value.c_str ()) < 0)
    return false;
  return true;
}

bool
BitcoinExchange::isDateValid (std::string date)
{
  const char *delimiter = "-";
  int tokenCount = 0, hifenCount = 0;
  char *token;

  for (size_t i = 0; i < date.size (); i++)
    {
      if (date[i] == '-')
        hifenCount++;
    }
  if (hifenCount != 2)
    return false;
  token = std::strtok (const_cast<char *> (date.c_str ()), delimiter);
  while (token != 0)
    {
      if (tokenCount == 0
          && (std::atoi (token) < 0 || std::atoi (token) > 2024))
        return false;
      if (tokenCount == 1 && (std::atoi (token) < 1 || std::atoi (token) > 12))
        return false;
      if (tokenCount == 2 && (std::atoi (token) < 1 || std::atoi (token) > 31))
        return false;
      tokenCount++;
      token = std::strtok (0, delimiter);
    }
  if (tokenCount != 3)
    return false;
  return true;
}

void
BitcoinExchange::validadeDatabaseLine (std::string line, size_t lineNumber)
{
  size_t i = 0, commaCount = 0;
  std::string error = RED "Database error: " RESET "line: ";
  std::stringstream lineNumberStr;

  lineNumberStr << lineNumber;
  error += lineNumberStr.str () + ": ";
  if (line.empty ())
    {
      error += "empty line";
      throw std::runtime_error (error.c_str ());
    }
  i = line.find (",");
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
  for (size_t j = 0; j < line.size (); j++)
    {
      if (line[j] == ',')
        commaCount++;
    }
  if (commaCount != 1)
    {
      error += "expected only 1 comma";
      throw std::runtime_error (error.c_str ());
    }
  if (isValueValid (line.substr (i + 1)) == false)
    {
      error += "invalid value";
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
          validadeDatabaseLine (line, lineNumber);
          i = line.find (",");
          if (i != std::string::npos)
            {
              std::string key = line.substr (0, i);
              double value = std::atof (line.substr (i + 1).c_str ());
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

void trim(std::string &str)
{
  str.erase(str.find_last_not_of(" ") + 1);
  str.erase(0, str.find_first_not_of(" "));
}