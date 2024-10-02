#include "gtest/gtest.h"
#include "Form.hpp"
#include "Bureaucrat.hpp"

// Test normal construction
TEST(FormTest, NormalConstruction) {
    EXPECT_NO_THROW(Form form(50, 100, "TestForm"));
}

// Test construction with signGrade too high
TEST(FormTest, SignGradeTooHigh) {
    EXPECT_THROW(Form form(0, 100, "TestForm"), Form::GradeTooHighException);
}

// Test construction with execGrade too high
TEST(FormTest, ExecGradeTooHigh) {
    EXPECT_THROW(Form form(50, 0, "TestForm"), Form::GradeTooHighException);
}

// Test construction with signGrade too low
TEST(FormTest, SignGradeTooLow) {
    EXPECT_THROW(Form form(151, 100, "TestForm"), Form::GradeTooLowException);
}

// Test construction with execGrade too low
TEST(FormTest, ExecGradeTooLow) {
    EXPECT_THROW(Form form(50, 151, "TestForm"), Form::GradeTooLowException);
}

// Test normal signing
TEST(FormTest, NormalSigning) {
    Bureaucrat bureaucrat("John", 50);
    Form form(100, 100, "TestForm");
    EXPECT_NO_THROW(form.beSigned(bureaucrat));
    EXPECT_TRUE(form.isSigned());  // Assuming there is a public method isSigned() to check _isSigned
}

// Test signing with a bureaucrat whose grade is too low
TEST(FormTest, SigningGradeTooLow) {
    Bureaucrat bureaucrat("John", 150);
    Form form(100, 100, "TestForm");
    EXPECT_THROW(form.beSigned(bureaucrat), Form::GradeTooLowException);
}
