#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int
main (void)
{
  ScavTrap scavTrap ("carla");
  ClapTrap clapTrap ("simone");

  print ("ClapTrap name: " << clapTrap.getName ());
  print ("ScavTrap name: " << scavTrap.getName ());

  print ("ClapTrap hit points: " << clapTrap.getHitPoints ());
  print ("ScavTrap hit points: " << scavTrap.getHitPoints ());

  print ("ClapTrap energy points: " << clapTrap.getEnergyPoints ());
  print ("ScavTrap energy points: " << scavTrap.getEnergyPoints ());

  print ("ClapTrap attack damage: " << clapTrap.getAttackDamage ());
  print ("ScavTrap attack damage: " << scavTrap.getAttackDamage ());

  clapTrap.attack ("enemy");
  scavTrap.attack ("enemy");

  scavTrap.guardGate ();
}
