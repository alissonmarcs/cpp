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
	static void convert (std::string str);
};
