#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(145, 137, "guest")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
	: AForm(145, 137, name)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
{
	
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}
