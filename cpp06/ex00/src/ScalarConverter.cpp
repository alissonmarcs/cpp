#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void) other;  return *this;}

ScalarConverter::~ScalarConverter() {}

const char *ScalarConverter::ImpossibleException::what() const throw() { return "impossible"; }

const char *ScalarConverter::NonDisplayableException::what() const throw() { return "Non displayable"; }

namespace Helpers
{
	bool isPseudoLiteral (std::string const str)
	{
		std::string pseudoLiterals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

		for (int i = 0; i < 6; i++)
		{
			if (str == pseudoLiterals[i])
				return true;
		}
		return false;
	}

	char toChar (std::string const str)
	{
		if (isPseudoLiteral(str))
			throw ScalarConverter::ImpossibleException();
		double result = std::strtod(str.c_str(), NULL);
		return ('a');
	}
}