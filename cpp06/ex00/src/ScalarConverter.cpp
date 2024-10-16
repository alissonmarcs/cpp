#include "ScalarConverter.hpp"

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
