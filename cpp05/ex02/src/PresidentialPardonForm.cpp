#include "PresidentialPardonForm.hpp"
#include "print.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm (25, 5, "PresidentialPardonForm"), _target("Nobody")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target)
	: AForm (25, 5, "PresidentialPardonForm"), _target(_target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
	: AForm(other), _target(other._target)
{
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	this->AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string
PresidentialPardonForm::getTarget() const
{
	return _target;
}

void
PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	print (getName() << " has been pardoned by Zafod Beeblebrox.");
}
