#pragma once

#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	const int _signGrade;
	const int _execGrade;
	bool _isSigned;

public:
	/* Canonical form */
	Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	/* Subject */
	std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;
	Form(int signGrade, int execGrade, std::string name);
	void beSigned(const Bureaucrat &bureaucrat);

class GradeTooLowException : public std::exception
{
	const char *what() const throw();
};

class GradeTooHighException : public std::exception
{
	const char *what() const throw();
};
};

std::ostream
&operator<<(std::ostream &out, const Form &object);
