#include <string>
#include <iostream>

int main(void)
{
	std::string		brain;
	std::string		*stringPTR;
	std::string		&stringREF = brain;

	brain = "HI THIS IS BRAIN";
	stringPTR = &brain;
	std::cout << "Addres of brain variable: " << &brain << std::endl;
	std::cout << "Addres held by stringPTR variable: " << stringPTR << std::endl;
	std::cout << "Addres held by stringREF reference" << &stringREF << std::endl;
	std::cout << "Value pointed by stringPTR variable: " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF reference (reference is not a var): " << stringREF << std::endl;
	std::cout << "Value of brain variable: " << brain << std::endl;
}