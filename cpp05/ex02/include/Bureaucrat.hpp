#pragma once

#include <string>

class AForm;

class Bureaucrat
{
private:
  const std::string _name;
  short _grade;

public:
  /* Canonical form */
  Bureaucrat ();
  Bureaucrat (const Bureaucrat &other);
  Bureaucrat &operator= (const Bureaucrat &other);
  ~Bureaucrat ();

  /* Subject */
  std::string getName () const;
  short getGrade () const;
  Bureaucrat (std::string name, short grade);
  void incrementGrade ();
  void decrementGrade ();
  void signForm (class AForm &form);

  class GradeTooLowException : public std::exception
  {
    const char *what () const throw ();
  };

  class GradeTooHighException : public std::exception
  {
    const char *what () const throw ();
  };
};

std::ostream &operator<< (std::ostream &out, const Bureaucrat &object);
