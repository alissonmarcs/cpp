#include "Animal.hpp"
#include "print.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

namespace Tests
{
void
Subject ()
{
  const Animal *meta = new Animal ();
  const Animal *j = new Dog ();
  const Animal *i = new Cat ();
  std::cout << j->getType () << " " << std::endl;
  std::cout << i->getType () << " " << std::endl;
  i->makeSound ();
  j->makeSound ();
  meta->makeSound ();

  delete meta;
  delete j;
  delete i;
}

void
makeSound ()
{
  Cat c;
  Dog d;
  Animal a;

  c.makeSound ();
  d.makeSound ();
  a.makeSound ();
}

void
WrongMakeSound ()
{
  WrongCat c;
  WrongAnimal a;

  c.makeSound ();
  a.makeSound ();
}
}

int
main()
{
  Dog a;
  Dog b(a);

  print (a.getBrain());
  print (b.getBrain());
  return 0;
}
