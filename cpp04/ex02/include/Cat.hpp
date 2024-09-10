#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"

class Cat : public Animal
{
private:
  Brain *brain;

public:
  /* Canonical form */
  Cat ();
  Cat (const Cat &other);
  Cat &operator= (const Cat &other);
  ~Cat ();

  /* Subject */
  void makeSound () const;
  Brain *getBrain () const;
};
