#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
  /* Canonical form */
  FragTrap ();
  FragTrap (const FragTrap &other);
  FragTrap &operator= (const FragTrap &other);
  ~FragTrap ();

  /* Subject */
  FragTrap (std::string name);
  void highFivesGuys ();
};
