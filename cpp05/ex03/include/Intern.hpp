#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "print.hpp"

class Intern
{
public:
	/* Canonical form */
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	/* Subject */
	AForm *makeForm(std::string name, std::string target);

	AForm *makePresidential(std::string target);
	AForm *makeRobotomy(std::string target);
	AForm *makeShrubbery(std::string target);

	class FormNotFoundException : public std::exception
	{
		const char *what() const throw ();
	};
};
