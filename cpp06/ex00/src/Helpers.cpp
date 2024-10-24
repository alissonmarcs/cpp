#include "Helpers.hpp"
#include "defines.hpp"

#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <limits>

namespace Helpers
{

bool
validade_string (std::string str)
{
  int dot = 0;
  size_t i = 0;

  if (isPseudoLiteral (str))
    return true;
  if ((std::isalpha (str[0]) && str.size () == 1))
    return true;
  if (str[i] == '-' || str[i] == '+')
    i++;
  if (!std::isdigit (str[i]) && str.size () > 1)
    return false;
  if (str.empty ())
    return false;
  for (; i < str.size (); i++)
    {
      if (str[i] == '.')
        dot++;
      if (!std::isdigit (str[i]) && str[i] != '.' && i != str.size () - 1)
        return false;
      if (!std::isdigit (str[i]) && i == str.size () - 1 && str[i] != 'f')
        return false;
    }
  if (str[str.size () - 1] == 'f' && dot != 1)
    return false;
  return true;
}

int
getType (std::string str)
{
  if (isChar (str))
    return CHAR;
  else if (isInt (str))
    return INT;
  else if (isFloat (str))
    return FLOAT;
  else if (isDouble (str))
    return DOUBLE;
  else if (isPseudoLiteral (str))
    return PSEUDO_LITERAL;
  return -1;
}

bool
isFloat (std::string str)
{
  int dot = 0;

  for (std::string::iterator it = str.begin (); it != str.end (); it++)
    {
      if (*it == '.')
        dot++;
    }
  if (dot == 1 && str[str.size () - 1] == 'f')
    return true;
  return false;
}

bool
isDouble (std::string str)
{
  int dot = 0;

  for (std::string::iterator it = str.begin (); it != str.end (); it++)
    {
      if (*it == '.')
        dot++;
    }
  if (dot == 1 && std::isdigit (str[str.size () - 1]))
    return true;
  return false;
}

bool
isInt (std::string str)
{
  int dot = 0;

  for (std::string::iterator it = str.begin (); it != str.end (); it++)
    {
      if (*it == '.')
        dot++;
      if (*it == '-' || *it == '+')
        ++it;
      if (!std::isdigit (*it))
        return false;
    }
  if (dot == 0)
    return true;
  return false;
}

bool
isChar (std::string str)
{
  if (str.size () == 1 && !std::isdigit (str[0]))
    return true;
  return false;
}

bool
isPseudoLiteral (std::string str)
{
  std::string literals[]
      = { "inf", "-inf", "+inf", "inff", "-inff", "+inff", "nan", "nanf" };

  for (size_t i = 0; i < 8; i++)
    {
      if (str == literals[i])
        return true;
    }
  return false;
}

void
printPseudoLiteral (std::string str)
{
    print (PURPLE << "char: " << RESET << "impossible");
    print (PURPLE << "int: " << RESET << "impossible");
    if (str[str.size() - 1] == 'f')
        print (PURPLE << "float: " << RESET << str);
    else
        print (PURPLE << "float: " << RESET << (str + "f"));
    print (PURPLE << "double: " << RESET << str);
}

void
printAllImpossible()
{
    print (PURPLE << "char: " << RESET << "impossible");
    print (PURPLE << "int: " << RESET << "impossible");
    print (PURPLE << "float: " << RESET << "impossible");
    print (PURPLE << "double: " << RESET << "impossible");
}

void
convertFromInt (std::string str)
{
    double toCheck = std::strtod(str.c_str(), NULL);
    if (toCheck > std::numeric_limits<int>::max() || toCheck < std::numeric_limits<int>::min())
    {
        printAllImpossible();
        return;
    }
    int i = std::atoi(str.c_str());
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    if (std::isprint(c))
        print (PURPLE << "char: " << RESET << c);
    else
        print (PURPLE << "char: " << RESET << "Non displayable");
    print (PURPLE << "int: " << RESET << i);
    print (PURPLE << "float: " << RESET << std::fixed << std::setprecision(1) << f << "f");
    print (PURPLE << "double: " << RESET << std::fixed << std::setprecision(1) << d);
}

void
convertFromChar (std::string str)
{
    char c = static_cast<char>(str[0]);
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    if (std::isprint(c))
        print (PURPLE << "char: " << RESET << c);
    else
        print (PURPLE << "char: " << RESET << "Non displayable");
    print (PURPLE << "int: " << RESET << i);
    print (PURPLE << "float: " << RESET << std::fixed << std::setprecision(1) << f << "f");
    print (PURPLE << "double: " << RESET << std::fixed << std::setprecision(1) << d);
}

void
convertFromFloat (std::string str)
{
  double toCheck = std::strtod(str.c_str(), NULL);
    if (toCheck > std::numeric_limits<float>::max() || toCheck < std::numeric_limits<float>::min())
    {
        printAllImpossible();
        return;
    }
    float f = strtof(str.c_str(), NULL);
    double d = static_cast<double>(f);
    int i = static_cast<int>(d);
    char c = static_cast<char>(i);

    if (std::isprint(c))
        print (PURPLE << "char: " << RESET << c);
    else
        print (PURPLE << "char: " << RESET << "Non displayable");
    print (PURPLE << "int: " << RESET << i);
    print (PURPLE << "float: " << RESET << std::fixed << std::setprecision(1) << f << "f");
    print (PURPLE << "double: " << RESET << std::fixed << std::setprecision(1) << d);
}

void
convertFromDouble (std::string str)
{
    double toCheck = std::strtod(str.c_str(), NULL);
    if (toCheck > std::numeric_limits<int>::max() || toCheck < std::numeric_limits<int>::min())
    {
        printAllImpossible();
        return;
    }
    
    double d = strtof(str.c_str(), NULL);
    float f = static_cast<float>(d);
    int i = static_cast<int>(f);
    char c = static_cast<char>(i);

    if (std::isprint(c))
        print (PURPLE << "char: " << RESET << std::setw(6) << c);
    else
        print (PURPLE << "char: " << RESET << "Non displayable");
    print (PURPLE << "int: " << RESET << i);
    print (PURPLE << "float: " << RESET << std::fixed << std::setprecision(1) << f << "f");
    print (PURPLE << "double: " << RESET << std::fixed << std::setprecision(1) << d);
}

}