#include "gtest/gtest.h"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

class AnimalTest : public ::testing::Test
{
protected:	
	Animal a;
	AnimalTest() {}
	~AnimalTest() {}
};

TEST_F(AnimalTest, EntireClass)
{
	EXPECT_EQ(a.getType(), "Default animal");

	a.setType("Cat");
	EXPECT_EQ(a.getType(), "Cat");

	/* Assigment operator */
	Animal dest;
	dest = a;
	EXPECT_EQ(dest.getType(), "Cat");
	
	/* Copy constructor */
	dest.setType("any type here");
	Animal copy(dest);
	EXPECT_EQ(copy.getType(), "any type here");

	/* makeSound() */
	testing::internal::CaptureStdout();
	dest.makeSound();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Animal sound\n");
}

TEST(AnimalCatDogTest, DefaultConstructor)
{
	Animal a;
	Cat c;
	Dog d;

	EXPECT_EQ(a.getType(), "Default animal");
	EXPECT_EQ(c.getType(), "Cat");
	EXPECT_EQ(d.getType(), "Dog");
}

TEST(AnimalCatDogTest, makeSound)
{
	Animal a;
	Cat c;
	Dog d;
	std::string output;

	testing::internal::CaptureStdout();
	a.makeSound();
	output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Animal sound\n");
	testing::internal::CaptureStdout();
	c.makeSound();
	output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Cat sound\n");
	testing::internal::CaptureStdout();
	d.makeSound();
	output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Dog sound\n");
}
