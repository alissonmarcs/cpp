#pragma once

#include <string>

class Bureaucrat;

class AForm
{
private:
  const std::string _name;
  const int _signGrade;
  const int _execGrade;
  bool _isSigned;

public:
  /* Canonical form */
  AForm ();
  AForm (const AForm &other);
  AForm &operator= (const AForm &other);
  ~AForm ();

  /* Subject */
  std::string getName () const;
  int getSignGrade () const;
  int getExecGrade () const;
  bool isSigned () const;
  AForm (int signGrade, int execGrade, std::string name);
  void beSigned (const Bureaucrat &bureaucrat);
  void execute(Bureaucrat const & executor) const;
  virtual void action() const = 0;

  class GradeTooLowException : public std::exception
  {
    const char *what () const throw ();
  };

  class GradeTooHighException : public std::exception
  {
    const char *what () const throw ();
  };

  class FormNotSignedException : public std::exception
  {
    const char *what () const throw ();
  };
};

std::ostream &operator<< (std::ostream &out, const AForm &object);
