#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	/* Canonical form */
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	/* Subject */
	PresidentialPardonForm(std::string name);
};
