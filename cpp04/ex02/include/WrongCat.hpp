#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
  /* Canonical form */
  WrongCat ();
  WrongCat (const WrongCat &other);
  void operator= (const WrongCat &other);
 
  /* Subject */
  void makeSound () const; ~WrongCat ();
};
