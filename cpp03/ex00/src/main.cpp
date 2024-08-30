#include "ClapTrap.hpp"

int
main (void)
{
  ClapTrap tmp ("alisson");

  print (tmp.getName ());
  tmp.attack ("carla");
  tmp.setAtackDamage (3);
  tmp.attack ("carla");
  tmp.setAtackDamage (-1);
  tmp.attack ("carla");
  print (tmp.getEnergyPoints ());
  tmp.setEnergyPoints (1);
  tmp.attack ("carla");
  tmp.attack ("carla");
}
