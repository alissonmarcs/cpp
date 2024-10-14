#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	const std::string _target;

public:
	/* Canonical form */
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	/* Subject */
	ShrubberyCreationForm(std::string target);
	std::string getTarget() const ;
	void execute(Bureaucrat const & executor) const;
};
