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
	static bool validade_string (std::string str);
	static bool isPseudoLiteral (std::string str);
	static void convert (std::string str);
	static void convertChar(std::string str);
	static void convertInt(std::string str);
	static void convertFloat(std::string str);
	static void convertDouble(std::string str);

};
