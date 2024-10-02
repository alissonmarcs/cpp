#pragma once

#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	short _grade;

public:
	/* Canonical form */
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	/* Subject */
	std::string getName() const;
	short getGrade() const;
	Bureaucrat(std::string name, short grade);
	void incrementGrade();
	void decrementGrade();
	void signForm(class Form &form);

class GradeTooLowException : public std::exception
{
	virtual const char *what() const throw();
};

class GradeTooHighException : public std::exception
{
	virtual const char *what() const throw();
};

};

std::ostream
&operator<<(std::ostream &out, const Bureaucrat &object);
