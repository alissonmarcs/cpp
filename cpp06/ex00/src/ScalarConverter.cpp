#include "ScalarConverter.hpp"
#include "Helpers.hpp"
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



void 
ScalarConverter::convert (std::string str)
{
	int type = Helpers::getType(str);

	switch (type)
	{
		case CHAR:
			Helpers::convertFromChar(str);
			break;
		case INT:
			Helpers::convertFromInt(str);
			break;
		case FLOAT:
			Helpers::convertFromFloat(str);
			break;
		case DOUBLE:
			Helpers::convertFromDouble(str);
			break;
		case PSEUDO_LITERAL:
			Helpers::printPseudoLiteral(str);
			break;
	}
}
