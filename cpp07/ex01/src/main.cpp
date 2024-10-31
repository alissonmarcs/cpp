#include "defines.hpp"
#include "iter.hpp"
#include <iostream>

template <typename T>
void
echo (T &i)
{
  std::cout << i << std::endl;
}

void
toUpper (std::string const &str)
{
  std::string &copy = const_cast<std::string &> (str);
  for (size_t i = 0; i < str.length (); i++)
    {
      copy[i] = std::toupper (str[i]);
    }
}

int
main (void)
{
  print (YELLOW TITTLE << "Welcome to ex01 - Iter" RESET);
  print (GREEN SUB_TITTLE << "Echoing an int array" RESET);
  int array[] = { 1, 2, 3, 4, 5 };
  iter (array, 5, echo<int>);

  print (GREEN SUB_TITTLE
         << "Upp Case an array of strings, and echoing it" RESET);
  std::string strArray[] = { "hello", "world", "c++", "is", "fun" };
  iter (strArray, 5, toUpper);
  iter (strArray, 5, echo<std::string>);

  return 0;
}