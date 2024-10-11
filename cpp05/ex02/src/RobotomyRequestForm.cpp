#include "RobotomyRequestForm.hpp"
#include "print.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm(72, 45, "guest")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string name)
	: AForm(72, 45, name)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
	: AForm(other)
{
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void
RobotomyRequestForm::action() const
{
	static short calls_number = 1;

	print ("Bzzzzzzzzzz");
	if (calls_number % 2)
		print (getName() << " has been robotomized successfully.");
	else
		print (getName() << " robotomization failed.");
	calls_number++;
}
