#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	/* Canonical form */
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	/* Subject */
	RobotomyRequestForm(std::string name);
	void execute(Bureaucrat const & executor) const;
};
