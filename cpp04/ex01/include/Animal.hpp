#pragma once

#include <string>

class Animal
{
protected:
  std::string _type;

public:
  /* Canonical form */
  Animal ();
  Animal (const Animal &other);
  Animal &operator= (const Animal &other);
  virtual ~Animal ();

  /* Subject */
  virtual void makeSound () const;
  std::string getType () const;
  void setType (std::string type);
};

