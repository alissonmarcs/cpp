#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string _target;

public:
	/* Canonical form */
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	/* Subject */
	PresidentialPardonForm(std::string target);
	std::string getTarget() const ;
	void execute(Bureaucrat const & executor) const;
};
