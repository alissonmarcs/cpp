#pragma once

#include <string>

class ScalarConverter
{
private:
	/* Canonical form */
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

public:
	/* Subject */
	static int getType (std::string str);
	static bool isFloat (std::string str);
	static bool isDouble(std::string str);
	static bool isChar (std::string str);
	static bool isInt(std::string str);
};
