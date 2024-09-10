#pragma once

class WrongAnimal
{
public:
  /* Canonical form */
  WrongAnimal ();
  WrongAnimal (const WrongAnimal &other);
  void operator= (const WrongAnimal &other);
  ~WrongAnimal ();

  /* Subject */
  void makeSound () const;
};
