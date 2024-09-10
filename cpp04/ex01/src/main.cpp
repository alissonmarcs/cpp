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

    print ("Dog Brain pointer: " << d.getBrain());
    // print ("Cat Brain pointer: " << c.getBrain());
  }
}

int
main()
{
  // Tests::catDogBrain();
  Dog src;
  Dog dst(src);

  print ("src Brain pointer: " << src.getBrain());
  print ("dst Brain pointer: " << dst.getBrain());
}
