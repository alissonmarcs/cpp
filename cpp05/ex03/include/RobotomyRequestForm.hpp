#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;

public:
	/* Canonical form */
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	/* Subject */
	RobotomyRequestForm(std::string target);
	std::string getTarget() const ;
	void execute(Bureaucrat const & executor) const;
};
