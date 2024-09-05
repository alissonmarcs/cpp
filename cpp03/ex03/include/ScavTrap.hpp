#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
  /* Canonical form */
  ScavTrap ();
  ScavTrap (const ScavTrap &other);
  ScavTrap &operator= (const ScavTrap &other);
  ~ScavTrap ();

  /* Subject */
  ScavTrap (std::string name);
  void guardGate ();
  void attack (const std::string &target);
};
