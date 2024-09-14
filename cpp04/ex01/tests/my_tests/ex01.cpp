#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "print.hpp"
#include "gtest/gtest.h"

TEST (Brain, copyConstrucor)
{
  Brain src;

  src.setIdea ("any idea", 0);
  src.setIdea ("i am thinking some idea", 31);
  src.setIdea ("i am batman", 99);

  Brain dst (src);
  EXPECT_EQ (dst.getIdea (0), "any idea");
  EXPECT_EQ (dst.getIdea (31), "i am thinking some idea");
  EXPECT_EQ (dst.getIdea (99), "i am batman");
}

TEST (Brain, assigmentOperator)
{
  Brain src;

  src.setIdea ("any idea", 50);
  src.setIdea ("i am thinking some idea", 51);
  src.setIdea ("i am batman", 80);

  Brain dst;
  dst = src;
  EXPECT_EQ (dst.getIdea (50), "any idea");
  EXPECT_EQ (dst.getIdea (51), "i am thinking some idea");
  EXPECT_EQ (dst.getIdea (80), "i am batman");
  for (int i = 0; i < 100; i++)
    {
      if (i != 50 && i != 51 && i != 80)
        EXPECT_TRUE (dst.getIdea (i).empty ());
    }
}

TEST (Dog, copyConstrucor)
{
  Dog src;

  src.getBrain ()->setIdea ("what is purpose of life ?", 75);
  src.getBrain ()->setIdea ("some idea here", 040);
  src.getBrain ()->setIdea ("hihihi", 31);

  Dog dst (src);
  EXPECT_NE (dst.getBrain (), src.getBrain ());
  EXPECT_EQ (dst.getBrain ()->getIdea (75), "what is purpose of life ?");
  EXPECT_EQ (dst.getBrain ()->getIdea (040), "some idea here");
  EXPECT_EQ (dst.getBrain ()->getIdea (31), "hihihi");

  EXPECT_NE (dst.getBrain (), src.getBrain ());
  for (int i = 0; i < 100; i++)
    {
      if (i != 75 && i != 040 && i != 31)
        EXPECT_TRUE (dst.getBrain ()->getIdea (i).empty ());
    }
}

TEST (Dog, assigmentOperator)
{
  Dog src;

  src.getBrain ()->setIdea ("any", 0);
  src.getBrain ()->setIdea ("i am thinking some idea", 1);
  src.getBrain ()->setIdea ("i am batman", 99);
  src.getBrain ()->setIdea ("i am spider man", 50);

  Dog dst;
  dst = src;
  EXPECT_NE (dst.getBrain (), src.getBrain ());
  EXPECT_EQ (dst.getBrain ()->getIdea (0), "any");
  EXPECT_EQ (dst.getBrain ()->getIdea (1), "i am thinking some idea");
  EXPECT_EQ (dst.getBrain ()->getIdea (50), "i am spider man");
  EXPECT_EQ (dst.getBrain ()->getIdea (99), "i am batman");
  for (int i = 0; i < 100; i++)
    {
      if (i != 0 && i != 1 && i != 50 && i != 99)
        EXPECT_TRUE (dst.getBrain ()->getIdea (i).empty ());
    }
}

TEST (Cat, copyConstrucor)
{
  Cat src;

  src.getBrain ()->setIdea ("what is purpose of life ?", 75);
  src.getBrain ()->setIdea ("some idea here", 040);
  src.getBrain ()->setIdea ("hihihi", 31);

  Cat dst (src);
  EXPECT_NE (dst.getBrain (), src.getBrain ());
  EXPECT_EQ (dst.getBrain ()->getIdea (75), "what is purpose of life ?");
  EXPECT_EQ (dst.getBrain ()->getIdea (040), "some idea here");
  EXPECT_EQ (dst.getBrain ()->getIdea (31), "hihihi");

  EXPECT_NE (dst.getBrain (), src.getBrain ());
  for (int i = 0; i < 100; i++)
    {
      if (i != 75 && i != 040 && i != 31)
        EXPECT_TRUE (dst.getBrain ()->getIdea (i).empty ());
    }
}

TEST (Cat, assigmentOperator)
{
  Cat src;

  src.getBrain ()->setIdea ("any", 0);
  src.getBrain ()->setIdea ("i am thinking some idea", 1);
  src.getBrain ()->setIdea ("i am batman", 99);
  src.getBrain ()->setIdea ("i am spider man", 50);

  Cat dst;
  dst = src;
  EXPECT_NE (dst.getBrain (), src.getBrain ());
  EXPECT_EQ (dst.getBrain ()->getIdea (0), "any");
  EXPECT_EQ (dst.getBrain ()->getIdea (1), "i am thinking some idea");
  EXPECT_EQ (dst.getBrain ()->getIdea (50), "i am spider man");
  EXPECT_EQ (dst.getBrain ()->getIdea (99), "i am batman");
  for (int i = 0; i < 100; i++)
    {
      if (i != 0 && i != 1 && i != 50 && i != 99)
        EXPECT_TRUE (dst.getBrain ()->getIdea (i).empty ());
    }
}

TEST (Cat, makeSound)
{
  Cat src;
  std::string output;

  testing::internal::CaptureStdout ();
  src.makeSound ();
  output = testing::internal::GetCapturedStdout ();
  EXPECT_EQ (output, "Cat sound\n");
}

TEST (Dog, makeSound)
{
  Dog src;
  std::string output;

  testing::internal::CaptureStdout ();
  src.makeSound ();
  output = testing::internal::GetCapturedStdout ();
  EXPECT_EQ (output, "Dog sound\n");
}
