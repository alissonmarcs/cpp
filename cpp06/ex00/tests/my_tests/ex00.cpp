#include "gtest/gtest.h"
#include "ScalarConverter.hpp"

bool validade_string (std::string str);

TEST(ValidateStringTest, ValidString) {
    std::string valid_str = "12345";
    EXPECT_TRUE(ScalarConverter::validade_string(valid_str));
}

TEST(ValidateStringTest, InvalidStringWithLetters) {
    std::string invalid_str = "123a45";
    EXPECT_FALSE(ScalarConverter::validade_string(invalid_str));
}

TEST(ValidateStringTest, EmptyString) {
    std::string empty_str = "";
    EXPECT_FALSE(ScalarConverter::validade_string(empty_str));
}

TEST(ValidateStringTest, StringWithOnlyDecimalPoint) {
    std::string decimal_str = ".";
    EXPECT_FALSE(ScalarConverter::validade_string(decimal_str));
}

TEST(ValidateStringTest, StringWithDecimalPointAndDigits) {
    std::string decimal_str = "123.45";
    EXPECT_TRUE(ScalarConverter::validade_string(decimal_str));
}

TEST(ValidateStringTest, my_own_test)
{
	std::string str = "32+";
	EXPECT_FALSE(ScalarConverter::validade_string(str));
	str = "3-2";
	EXPECT_FALSE(ScalarConverter::validade_string(str));
	str = "30f";
	EXPECT_FALSE(ScalarConverter::validade_string(str));
	str = "30n";
	EXPECT_FALSE(ScalarConverter::validade_string(str));
	str = "30.0f";
	EXPECT_TRUE(ScalarConverter::validade_string(str));
	str = "30.0";
	EXPECT_TRUE(ScalarConverter::validade_string(str));	
	str = "3.0A";
	EXPECT_FALSE(ScalarConverter::validade_string(str));
	str = "-30.4f";
	EXPECT_TRUE(ScalarConverter::validade_string(str));
	str = "+30.4f";
	EXPECT_TRUE(ScalarConverter::validade_string(str));
	str = "+30.4f-";
	EXPECT_FALSE(ScalarConverter::validade_string(str));
	str = "d";
	EXPECT_TRUE(ScalarConverter::validade_string(str));
	str = "f";
	EXPECT_TRUE(ScalarConverter::validade_string(str));
}
