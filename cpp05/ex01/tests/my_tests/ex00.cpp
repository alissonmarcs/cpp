#include "Bureaucrat.hpp"
#include "gtest/gtest.h"

TEST (BureaucratTest, IncrementGradeNormal)
{
  Bureaucrat b ("John Doe", 100);
  b.incrementGrade ();
  EXPECT_EQ (b.getGrade (), 99);
}

TEST (BureaucratTest, IncrementGradeBoundary)
{
  Bureaucrat b ("Jane Doe", 1);
  EXPECT_THROW (b.incrementGrade (), Bureaucrat::GradeTooHighException);
}

TEST (BureaucratTest, DecrementGradeNormal)
{
  Bureaucrat b ("John Doe", 100);
  b.decrementGrade ();
  EXPECT_EQ (b.getGrade (), 101);
}

TEST (BureaucratTest, DecrementGradeBoundary)
{
  Bureaucrat b ("Jane Doe", 150);
  EXPECT_THROW (b.decrementGrade (), Bureaucrat::GradeTooLowException);
}

TEST (BureaucratTest, CopyConstructor)
{
  Bureaucrat original ("John Doe", 100);
  Bureaucrat copy (original);

  EXPECT_EQ (copy.getName (), original.getName ());
  EXPECT_EQ (copy.getGrade (), original.getGrade ());
}

TEST (BureaucratTest, AssignmentOperator)
{
  Bureaucrat original ("John Doe", 100);
  Bureaucrat assigned ("Jane Doe", 50);

  assigned = original;

  EXPECT_EQ (assigned.getGrade (), original.getGrade ());
  // Note: The name should not change as it is a const member
  EXPECT_EQ (assigned.getName (), "Jane Doe");
}
