#include "ScalarConverter.hpp"
#include "defines.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) 
{
	(void)other;
}

ScalarConverter &
ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool
ScalarConverter::isFloat(std::string str)
{
	int dot = 0;

	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (*it == '.')
			dot++;
	}
	if (dot == 1 && str[str.size () - 1] == 'f')
		return true;
	return false;
}

bool
ScalarConverter::isDouble(std::string str)
{
	int dot = 0;

	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (*it == '.')
			dot++;
	}
	if (dot == 1 && std::isdigit(str[str.size () - 1]))
		return true;
	return false;
}

bool
ScalarConverter::isInt(std::string str)
{
	int dot = 0;

	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (*it == '.')
			dot++;
		if (*it == '-' || *it == '+')
			++it;
		if (!std::isdigit(*it))
			return false;
	}
	if (dot == 0)
		return true;
	return false;
}

bool
ScalarConverter::isChar(std::string str)
{
	if (str.size() == 1 && !std::isdigit(str[0]))
		return true;
	return false;
}

bool 
ScalarConverter::validade_string (std::string str)
{
	int dot = 0;
	size_t i = 0;

	if (ScalarConverter::isPseudoLiteral(str))
		return true;
	if ((std::isalpha(str[0]) && str.size() == 1))
		return true;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!std::isdigit(str[i]) && str.size() > 1)
		return false;
	if (str.empty())
		return false;
	for (; i < str.size(); i++)
	{
		if (str[i] == '.')
			dot++;
		if (!std::isdigit(str[i]) && str[i] != '.' && i != str.size() - 1)
			return false;
		if (!std::isdigit(str[i]) && i == str.size() - 1 && str[i] != 'f')
			return false;
	}
	if (str[str.size() - 1] == 'f' && dot != 1)
		return false;
	return true;
}

bool 
ScalarConverter::isPseudoLiteral (std::string str)
{
	std::string literals[] = {"inf", "-inf", "+inf", "inff", "-inff", "+inff", "nan", "nanf"};

	for (size_t i = 0; i < 8; i++)
	{
		if (str == literals[i])
			return true;
	}
	return false;
}

int 
ScalarConverter::getType (std::string str)
{
	if (ScalarConverter::isChar(str))
		return CHAR;
	else if (ScalarConverter::isInt(str))
		return INT;
	else if (ScalarConverter::isFloat(str))
		return FLOAT;
	else if (ScalarConverter::isDouble(str))
		return DOUBLE;
	return -1;
}

void 
ScalarConverter::convert (std::string str)
{
	int type = ScalarConverter::getType(str);

	switch (type)
	{
		case CHAR:
			ScalarConverter::convertChar(str);
			break;
		case INT:
			ScalarConverter::convertInt(str);
			break;
		case FLOAT:
			ScalarConverter::convertFloat(str);
			break;
		case DOUBLE:
			ScalarConverter::convertDouble(str);
			break;
		default:
			print(RED_BOLD "Error: " RESET "Invalid input");
			break;
	}
}

void
ScalarConverter::convertChar (std::string str)
{
}

void
ScalarConverter::convertInt (std::string str)
{
}

void
ScalarConverter::convertDouble (std::string str)
{
}

void
ScalarConverter::convertFloat (std::string str)
{
}
