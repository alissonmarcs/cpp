#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm (25, 5, "guest")
{
	
}
PresidentialPardonForm::PresidentialPardonForm(std::string name)
	
	: AForm (25, 5, name)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
{
	
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}
