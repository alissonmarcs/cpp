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
};
