#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "print.hpp"

namespace Tests
{
void
catDogBrain ()
{
  Dog d;
  Cat c;

  print ("Dog's Brain pointer: " << d.getBrain ());
  print ("Cat's Brain pointer: " << c.getBrain ());
}

void
dogDeepCopy ()
{
  Dog src;

  src.getBrain ()->setIdea ("what is purpose of life ?", 75);
  src.getBrain ()->setIdea ("some idea here", 040);
  src.getBrain ()->setIdea ("hihihi", 31);
  src.getBrain ()->setIdea ("i am batman", 42);

  Dog dst = src;
  print ("Dog src Brain pointer: " << src.getBrain ());
  print ("Dog dst Brain pointer: " << dst.getBrain ());

  print ("dst data get from src:");
  print ("\t" << dst.getBrain ()->getIdea (75));
  print ("\t" << dst.getBrain ()->getIdea (040));
  print ("\t" << dst.getBrain ()->getIdea (31));
  print ("\t" << dst.getBrain ()->getIdea (42));
}

void
catDeepCopy ()
{
  Cat src;

  src.getBrain ()->setIdea ("what is purpose of life ?", 75);
  src.getBrain ()->setIdea ("some idea here", 040);
  src.getBrain ()->setIdea ("hihihi", 31);
  src.getBrain ()->setIdea ("i am batman", 42);

  Cat dst = src;
  print ("Cat src Brain pointer: " << src.getBrain ());
  print ("Cat dst Brain pointer: " << dst.getBrain ());

  print ("dst data get from src:");
  print ("\t" << dst.getBrain ()->getIdea (75));
  print ("\t" << dst.getBrain ()->getIdea (040));
  print ("\t" << dst.getBrain ()->getIdea (31));
  print ("\t" << dst.getBrain ()->getIdea (42));
}

void
DogAssigementOperator ()
{
  Dog src;
  Dog dst;

  src.getBrain ()->setIdea ("what is purpose of life ?", 75);
  src.getBrain ()->setIdea ("some idea here", 040);
  src.getBrain ()->setIdea ("hihihi", 31);
  src.getBrain ()->setIdea ("i am batman", 42);
  dst = src;
  print ("dst data get from src:");
  print ("\t" << dst.getBrain ()->getIdea (75));
  print ("\t" << dst.getBrain ()->getIdea (040));
  print ("\t" << dst.getBrain ()->getIdea (31));
  print ("\t" << dst.getBrain ()->getIdea (42));
  print ("dst Brain pointer: " << dst.getBrain ());
  print ("src Brain pointer: " << src.getBrain ());
}

void
CatAssigementOperator ()
{
  Cat src;
  Cat dst;

  src.getBrain ()->setIdea ("what is purpose of life ?", 75);
  src.getBrain ()->setIdea ("some idea here", 040);
  src.getBrain ()->setIdea ("hihihi", 31);
  src.getBrain ()->setIdea ("i am batman", 42);
  dst = src;
  print ("dst data get from src:");
  print ("\t" << dst.getBrain ()->getIdea (75));
  print ("\t" << dst.getBrain ()->getIdea (040));
  print ("\t" << dst.getBrain ()->getIdea (31));
  print ("\t" << dst.getBrain ()->getIdea (42));
  print ("dst Brain pointer: " << dst.getBrain ());
  print ("src Brain pointer: " << src.getBrain ());
}

void
Subject ()
{
  int size = 6;
  Animal *array[size];

  for (int i = 0; i < size; i++)
    {
      if (i < size / 2)
        array[i] = new Dog ();
      else
        array[i] = new Cat ();
    }
  for (int i = 0; i < size; i++)
    {
      delete array[i];
    }
}

void
MakeSound ()
{
  Dog d;
  Cat c;

  d.makeSound ();
  c.makeSound ();
}
}

int
main ()
{
  print ("\n\n\t\tCat and Dog must have a private pointer to Brain\n");
  Tests::catDogBrain ();

  print ("\n\n\t\tWhen copying, Dog must alocate a new Brain object\n");
  Tests::dogDeepCopy ();

  print ("\n\n\t\tWhen copying, Cat must alocate a new Brain object\n");
  Tests::catDeepCopy ();

  print ("\n\n\t\tDog assigment operator\n");
  Tests::DogAssigementOperator ();

  print ("\n\n\t\tCat assigment operator\n");
  Tests::CatAssigementOperator ();

  print ("\n\n\t\tMake sound test\n");
  Tests::MakeSound ();

  print ("\n\n\t\t Delete Cat and Dog objects using Animal pointer should not "
         "result a leak\n");
  Tests::Subject ();
}
