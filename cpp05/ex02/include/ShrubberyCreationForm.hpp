#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
public:
	/* Canonical form */
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	/* Subject */
	ShrubberyCreationForm(std::string name);
};
