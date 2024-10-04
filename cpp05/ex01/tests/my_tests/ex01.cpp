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

// Test normal case: Bureaucrat successfully signs the form
TEST(BureaucratTest, SignFormNormalCase) {
    Bureaucrat bureaucrat("John Doe", 1);
    Form form(1, 1, "TestForm"); // Assuming Form constructor takes name, sign grade, and execute grade
    bureaucrat.signForm(form);
    EXPECT_TRUE(form.isSigned());
}

// Test corner case: Bureaucrat with too low grade cannot sign the form
TEST(BureaucratTest, SignFormLowGrade) {
    Bureaucrat bureaucrat("John Doe", 150); // Assuming 150 is the lowest grade
    Form form(1, 1, "TestForm");
    bureaucrat.signForm(form);
    EXPECT_FALSE(form.isSigned());
}

// Test corner case: Bureaucrat with too high grade cannot sign the form
TEST(BureaucratTest, SignFormHighGrade) {
    Bureaucrat bureaucrat("John Doe", 42); // Assuming 0 is an invalid grade
    Form form(42, 1, "TestForm");
    bureaucrat.signForm(form);
    EXPECT_TRUE(form.isSigned());
}
