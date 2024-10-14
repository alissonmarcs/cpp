#include "Intern.hpp"

Intern::Intern () {}

Intern::Intern (const Intern &other) { (void)other; }

Intern &
Intern::operator= (const Intern &other)
{
  (void)other;
  return *this;
}

Intern::~Intern () {}

AForm *
Intern::makePresidential (std::string target)
{
  return new PresidentialPardonForm (target);
}

AForm *
Intern::makeRobotomy (std::string target)
{
  return new RobotomyRequestForm (target);
}

AForm *
Intern::makeShrubbery (std::string target)
{
  return new ShrubberyCreationForm (target);
}

AForm *
Intern::makeForm (std::string name, std::string target)
{
  AForm *(Intern::*forms[3]) (std::string)
      = { &Intern::makePresidential, &Intern::makeRobotomy,
          &Intern::makeShrubbery };

  std::string forms_names[3]
      = { "presidential pardon", "robotomy request", "shrubbery creation" };
  for (int i = 0; i < 3; i++)
    {
      if (name == forms_names[i])
        return (this->*forms[i]) (target);
    }
  throw Intern::FormNotFoundException ();
}

const char *
Intern::FormNotFoundException::what () const throw ()
{
  return "Form not found";
}
