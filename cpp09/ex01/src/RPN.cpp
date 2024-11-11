#include "RPN.hpp"

#include <cstdlib>
#include <stdexcept>

void validadeExpression(std::string expression)
{
	size_t i = 0;

	while (i < expression.size())
	{
		if (!std::isdigit(expression[i]) && expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/' && expression[i] != ' ')
			throw std::invalid_argument("Invalid character in expression");
		if (std::atoi (&expression[i]) < 0 || std::atoi(&expression[i]) > 9)
			throw std::invalid_argument("Numbers must be between 0 and 9");
		i++;
	}	
}

RPN::RPN(std::string expression)
{
	validadeExpression(expression);
}

RPN::RPN()
{
	
}

RPN::RPN(const RPN &other) 
{
	(void) other;
}

RPN &
RPN::operator=(const RPN &other)
{
	(void) other;
	return *this;
}

RPN::~RPN()
{
	
}
