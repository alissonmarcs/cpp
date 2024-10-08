#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
  /* Canonical form */
  DiamondTrap ();
  DiamondTrap (const DiamondTrap &other);
  DiamondTrap &operator= (const DiamondTrap &other);
  ~DiamondTrap ();

  /* Subject */
  DiamondTrap (std::string name);
  void attack (const std::string &target);
  void whoAmI ();
  std::string getName () const;
  void setName (std::string name);

private:
  std::string _name;
};
