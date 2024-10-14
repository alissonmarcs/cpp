#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "print.hpp"
#include "gtest/gtest.h"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

// ===== Concrete forms exceptions =====

// PresidentialPardonForm

TEST (PresidentialPardonFormTest, noSignedTryExecute)
{
  Bureaucrat to_sign ("John", 10);
  PresidentialPardonForm form ("TestForm");

  EXPECT_EQ(form.getExecGrade(), 5);
  EXPECT_THROW (form.execute (to_sign), PresidentialPardonForm::FormNotSignedException);
}

TEST (PresidentialPardonFormTest, lowGradeTryExecute)
{
  Bureaucrat to_sign ("John", 24);
  Bureaucrat to_execute ("Maya", 10);
  PresidentialPardonForm form ("TestForm");

  form.beSigned (to_sign);
  EXPECT_THROW (form.execute (to_execute), Bureaucrat::GradeTooLowException);
}

// ShrubberyCreationForm

TEST (ShrubberyCreationFormTest, noSignedTryExecute)
{
  Bureaucrat to_sign ("John", 136);
  ShrubberyCreationForm form ("TestForm");

  EXPECT_THROW (form.execute (to_sign), PresidentialPardonForm::FormNotSignedException);
}

TEST (ShrubberyCreationFormTest, lowGradeTryExecute)
{
  Bureaucrat to_sign_and_exec ("John", 144);
  ShrubberyCreationForm form ("TestForm");

  form.beSigned (to_sign_and_exec);
  EXPECT_THROW (form.execute (to_sign_and_exec), Bureaucrat::GradeTooLowException);
}

// RobotomyRequestForm

TEST (RobotomyRequestFormTest, noSignedTryExecute)
{
  Bureaucrat to_sign ("John", 136);
  RobotomyRequestForm form ("TestForm");

  EXPECT_THROW (form.execute (to_sign), PresidentialPardonForm::FormNotSignedException);
}

TEST (RobotomyRequestFormTest, lowGradeTryExecute)
{
  Bureaucrat to_sign_and_exec ("John", 72);
  RobotomyRequestForm form ("TestForm");

  form.beSigned (to_sign_and_exec);
  EXPECT_THROW (form.execute (to_sign_and_exec), Bureaucrat::GradeTooLowException);
}

// ===== Target Constructors =====

TEST (ShrubberyCreationFormTest, targetConstructor)
{
  ShrubberyCreationForm form ("Batman");

  EXPECT_EQ(form.getSignGrade(), 145);
  EXPECT_EQ(form.getExecGrade(), 137);
  EXPECT_EQ(form.getName(), "ShrubberyCreationForm");
  EXPECT_EQ(form.getTarget(), "Batman");
}

TEST (RobotomyRequestForm, targetConstructor)
{
  RobotomyRequestForm form ("Spider Man");

  EXPECT_EQ(form.getSignGrade(), 72);
  EXPECT_EQ(form.getExecGrade(), 45);
  EXPECT_EQ(form.getName(), "RobotomyRequestForm");
  EXPECT_EQ(form.getTarget(), "Spider Man");
}

TEST (PresidentialPardonFormTest, targetConstructor)
{
  PresidentialPardonForm form ("Wonder Woman");

  EXPECT_EQ(form.getSignGrade(), 25);
  EXPECT_EQ(form.getExecGrade(), 5);
  EXPECT_EQ(form.getName(), "PresidentialPardonForm");
  EXPECT_EQ(form.getTarget(), "Wonder Woman");
}
