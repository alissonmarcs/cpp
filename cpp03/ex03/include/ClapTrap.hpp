#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
public:
  /* Cannonical form */
  ClapTrap ();
  ClapTrap (const ClapTrap &other);
  ClapTrap &operator= (const ClapTrap &other);
  ~ClapTrap ();
  ClapTrap (std::string name);

  /* Subject */
  void attack (const std::string &target);
  void takeDamage (unsigned int amount);
  void beRepaired (unsigned int amount);

  /* Getters and Setters */
  int getEnergyPoints () const;
  void setEnergyPoints (int amount);
  int getHitPoints () const;
  void setHitPoints (int amount);
  int getAttackDamage () const;
  void setAttackDamage (int amount);
  std::string getName () const;
  void setName (std::string name);

protected:
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;
};

#define print(s) std::cout << s << std::endl
