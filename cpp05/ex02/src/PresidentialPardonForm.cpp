#include "PresidentialPardonForm.hpp"
#include "print.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm (25, 5, "guest")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string name)
	: AForm (25, 5, name)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
	: AForm(other)
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

void
PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	print (getName() << " has been pardoned by Zafod Beeblebrox.");
}
