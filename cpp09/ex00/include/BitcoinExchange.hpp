#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
private:
  std::map<std::string, double> _Database;

public:
  BitcoinExchange ();
  BitcoinExchange (const BitcoinExchange &other);
  BitcoinExchange &operator= (const BitcoinExchange &other);
  ~BitcoinExchange ();

  BitcoinExchange (int argc, char **argv);
  void loadDatabase (std::string filename);
  void validadeDatabaseLine (std::string line, size_t lineNumber);
  bool isDateValid (std::string date);
  bool isValueValid (std::string date);
  bool haveAplha (std::string str);

  std::map<std::string, double>::iterator
  getNearestDate (std::string inputDate);
  void validadeInputLine (std::string line);
  void printData (std::ifstream &file);
  void trim (std::string &str);
};