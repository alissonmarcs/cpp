#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm(72, 45, "guest")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string name)
	: AForm(72, 45, name)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
{
	
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}
