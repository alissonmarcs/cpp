#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
public:
  BitcoinExchange ();
  BitcoinExchange (const BitcoinExchange &other);
  BitcoinExchange &operator= (const BitcoinExchange &other);
  ~BitcoinExchange ();

  std::map<std::string, float> *
  loadDatabase (std::string filename);

  void validadeDatabaseLine(std::string line, size_t line_number);
  bool haveAplha (std::string str);
};
