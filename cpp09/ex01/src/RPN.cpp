#include "RPN.hpp"
#include "Defines.hpp"

#include <cstdlib>
#include <sstream>
#include <stdexcept>

bool
RPN::isOperator (std::string str)
{
  if (str == "+" || str == "-" || str == "*" || str == "/")
    return true;
  return false;
}

void
RPN::executeOperator (std::stack<int> &stk, int first, std::string token,
                 int second)
{
  if (token == "+")
    stk.push (second + first);
  else if (token == "-")
    stk.push (second - first);
  else if (token == "*")
    stk.push (second * first);
  else if (token == "/")
    {
      if (first == 0)
        throw std::invalid_argument ("Division by zero");
      stk.push (second / first);
    }
}

RPN::RPN (std::string expression)
{
  std::stack<int> stk;
  int first, second;
  std::string token;
  std::istringstream iss (expression);

  while (iss >> token)
    {
      if (isOperator (token))
        {
          if (stk.size () < 2)
            throw std::invalid_argument ("Not enough numbers for operation");
          first = stk.top ();
          stk.pop ();
          second = stk.top ();
          stk.pop ();
          executeOperator (stk, first, token, second);
        }
      else if (std::isdigit (token[0]))
        {
          int number = std::atoi (token.c_str ());
          if (number < 0 || number > 9)
            throw std::invalid_argument ("Numbers must be between 0 and 9");
          stk.push (number);
        }
      else
        throw std::invalid_argument ("Invalid character in expression");
    }
  if (stk.size () != 1)
    throw std::invalid_argument ("Numbers were left in the stack");
  print (stk.top ());
}

RPN::RPN () {}

RPN::RPN (const RPN &other) { (void)other; }

RPN &
RPN::operator= (const RPN &other)
{
  (void)other;
  return *this;
}

RPN::~RPN () {}
