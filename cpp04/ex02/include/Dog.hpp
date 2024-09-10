#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"

class Dog : public Animal
{
private:
  Brain *brain;

public:
  /* Canonical form */
  Dog ();
  Dog (const Dog &other);
  Dog &operator= (const Dog &other);
  ~Dog ();

  /* Subject */
  void makeSound () const;
  Brain *getBrain () const;
};
