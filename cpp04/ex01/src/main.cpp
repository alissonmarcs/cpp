#include "Animal.hpp"
#include "print.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

namespace Tests
{
  void catDogBrain()
  {
    Dog d;
    Cat c;

    print ("Dog's Brain pointer: " << d.getBrain());
    print ("Cat's Brain pointer: " << c.getBrain());
  }

  void dogDeepCopy()
  {
    Dog src;

    src.getBrain()->setIdea("what is purpose of life ?", 75);
    src.getBrain()->setIdea("some idea here", 040);
    src.getBrain()->setIdea("hihihi", 31);
    src.getBrain()->setIdea("i am batman", 42);

    Dog dst = src;
    print ("Dog src Brain pointer: " << src.getBrain());
    print ("Dog dst Brain pointer: " << dst.getBrain());

    print ("dst data get from src:");
    print ("\t" << dst.getBrain()->getIdea(75));
    print ("\t" << dst.getBrain()->getIdea(040));
    print ("\t" << dst.getBrain()->getIdea(31));
    print ("\t" << dst.getBrain()->getIdea(42));
  }

  void catDeepCopy()
  {
    Cat src;

    src.getBrain()->setIdea("what is purpose of life ?", 75);
    src.getBrain()->setIdea("some idea here", 040);
    src.getBrain()->setIdea("hihihi", 31);
    src.getBrain()->setIdea("i am batman", 42);

    Cat dst = src;
    print ("Cat src Brain pointer: " << src.getBrain());
    print ("Cat dst Brain pointer: " << dst.getBrain());

    print ("dst data get from src:");
    print ("\t" << dst.getBrain()->getIdea(75));
    print ("\t" << dst.getBrain()->getIdea(040));
    print ("\t" << dst.getBrain()->getIdea(31));
    print ("\t" << dst.getBrain()->getIdea(42));
  } 

  void Subject()
  {
    int size = 6;
    Animal *array[size];

    for (int i = 0; i < size; i++)
    {
      if (i < size / 2)
        array[i] = new Dog();
      else
        array[i] = new Cat();
    }
    for (int i = 0; i < size; i++)
    {
      delete array[i];
    }
  }
}

int
main()
{
  print ("\n\n\t\tTesting Brain private pointer of Cat and Dog\n");
  Tests::catDogBrain();

  print ("\n\n\t\tTesting deep copy of Dog\n");
  Tests::dogDeepCopy();

  print ("\n\n\t\tTesting deep copy of Cat\n");
  Tests::catDeepCopy();

  print ("\n\n\t\t Subject Test\n");
  Tests::Subject();
}
