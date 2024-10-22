#include <string>

namespace Helpers
{
int getType (std::string str);
bool isFloat (std::string str);
bool isDouble (std::string str);
bool isChar (std::string str);
bool isInt (std::string str);
bool validade_string (std::string str);
bool isPseudoLiteral (std::string str);
void printPseudoLiteral (std::string str);
void convertChar (std::string str);
void convertInt (std::string str);
void convertFloat (std::string str);
void convertDouble (std::string str);
void convertFromChar (std::string str);
void convertFromInt (std::string str);
void convertFromFloat (std::string str);
void convertFromDouble (std::string str);
std::string handleFloatDecimal (std::string str);
};