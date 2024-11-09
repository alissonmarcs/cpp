#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
public:
  std::map<std::string, float> _Database;

public:
  BitcoinExchange ();
  BitcoinExchange (const BitcoinExchange &other);
  BitcoinExchange &operator= (const BitcoinExchange &other);
  ~BitcoinExchange ();

  void loadDatabase (std::string filename);

  void validadeDatabaseLine(std::string line, size_t line_number);
  bool isDateValid(std::string date);
  bool isValueValid(std::string date);
  bool haveAplha (std::string str);

  std::map<std::string, float>::iterator
  getNearestDate(std::string inputDate);
};
