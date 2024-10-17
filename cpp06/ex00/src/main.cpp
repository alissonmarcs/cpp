#include "defines.hpp"
#include "ScalarConverter.hpp"

bool validade_string (std::string str)
{
	int i = 0;
	int dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!std::isdigit(str[i]) && str.size() > 1)
		return false;
	else if (str.empty())
		return false;
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
		if (*it == '.')
			dot++;
	if (str[str.size() - 1] == 'f' && dot != 1)
		return false;
	return true;
}

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		print (RED "Error: " RESET "Usage: ./ex00 [string]");
		return 1;
	}
	else if (!validade_string(argv[1]))
	{
		print (RED "Error: " RESET "Invalid string");
		return 1;
	}
	print ("isFloat: " << ScalarConverter::isFloat(argv[1]));
	print ("isDouble: " << ScalarConverter::isDouble(argv[1]));
	print ("isChar: " << ScalarConverter::isChar(argv[1]));
	print ("isInt: " << ScalarConverter::isInt(argv[1]));
	return 0;
}
