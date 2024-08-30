#include "ClapTrap.hpp"

int
main (void)
{
  ClapTrap claptrap("alisson");
  std::cout << claptrap.getHitPoints() << std::endl;
  std::cout << claptrap.getEnergyPoints() << std::endl;
  std::cout << claptrap.getAttackDamage() << std::endl;


  claptrap.attack("carla");
  claptrap.setAtackDamage(3);
  claptrap.attack("carla");
  claptrap.takeDamage(5);
  std::cout << claptrap.getHitPoints() << std::endl;
}
