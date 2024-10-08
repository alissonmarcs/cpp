#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "print.hpp"
#include "gtest/gtest.h"

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
  EXPECT_THROW (form.execute (to_execute), PresidentialPardonForm::GradeTooLowException);
}
