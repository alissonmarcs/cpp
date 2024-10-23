#include "Helpers.hpp"
#include "defines.hpp"

#include <cstdlib>
#include <cctype>

namespace Helpers
{

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

void
printPseudoLiteral (std::string str)
{
    print (PURPLE << "char: " << RESET << "impossible");
    print (PURPLE << "int: " << RESET << "impossible");
    print (PURPLE << "float: " << RESET << (str + "f"));
    print (PURPLE << "double: " << RESET << str);
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
    print (PURPLE << "int: "<< RESET << i);
    print (PURPLE << "float: " << RESET << f);
    print (PURPLE << "double: " << RESET << d);
}

void
convertFromInt (std::string str)
{
    int i = std::atoi(str.c_str());
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    if (std::isprint(c))
        print (PURPLE << "char: " << RESET << c);
    else
        print (PURPLE << "char: " << RESET << "Non displayable");
    print (PURPLE << "int: "<< RESET << i);
    print (PURPLE << "float: " << RESET << f << ".0f");
    print (PURPLE << "double: " << RESET << d);
}

std::string
handleFloatDecimal (std::string str)
{
    size_t pos = str.find('.');
    if (pos == std::string::npos)
        return "";
    return str.substr(pos + 1);
}

void
convertFromFloat (std::string str)
{
}

void
convertFromDouble (std::string str)
{
}

}