#include "ClapTrap.hpp"
#include <iomanip>

int
main (void)
{

{
  print ("\n\t\tAttributes initialization\n");

  ClapTrap tmp ("teste");

  print (std::left << std::setw(18) << "Name: " << tmp.getName ());
  print (std::left << std::setw(18) << "Hit points: " << tmp.getHitPoints ());
  print (std::left << std::setw(18) << "Energy points: " << tmp.getEnergyPoints ());
  print (std::left << std::setw(18) << "Attack damage: " << tmp.getAttackDamage ());
}

{
  print ("\n\t\tAttack method when have no energy or hit points\n");

  ClapTrap tmp ("teste");

  tmp.setHitPoints (0);
  print (std::left << std::setw(18) << "Hit points: " << tmp.getHitPoints ());
  tmp.attack ("carla");
  tmp.setHitPoints (1);
  tmp.setEnergyPoints (0);
  print (std::left << std::setw(18) << "Energy points: " << tmp.getEnergyPoints ());
  tmp.attack ("carla");
  tmp.setHitPoints (1);
  tmp.setEnergyPoints (1);
  print (std::left << std::setw(18) << "Energy points: " << tmp.getEnergyPoints ());
  print (std::left << std::setw(18) << "Hit points: " << tmp.getHitPoints ());
  tmp.attack ("carla");
}

{
  print ("\n\t\tAttacking and reparing must decrement one energy point\n");

  ClapTrap tmp ("teste");

  print (std::left << std::setw(32) << "Energy points at creation: " << tmp.getEnergyPoints ());
  tmp.attack ("carla");
  print (std::left << std::setw(32) << "Energy points after attack: " << tmp.getEnergyPoints ());
  print (std::left << std::setw(32) << "Hit points before repair: " << tmp.getHitPoints ());
  tmp.beRepaired (1);
  print (std::left << std::setw(32) << "Energy  points after repair: " << tmp.getEnergyPoints ());
  print (std::left << std::setw(32) << "Hit points after repair: " << tmp.getHitPoints ());
}

{
  print ("\n\t\tAssigment operator\n");

  ClapTrap tmp ("teste");
  ClapTrap tmp2;

  tmp.setHitPoints(2);
  tmp.setEnergyPoints(2);
  tmp2 = tmp;
  print ("Tmp2 energy points: " << tmp2.getEnergyPoints ());
  print ("Tmp2 hit points: " << tmp2.getEnergyPoints ());
}

{
  print ("\n\t\tCopy constructor\n");

  ClapTrap tmp ("teste");
  tmp.setHitPoints(42);
  tmp.setEnergyPoints(42);
  tmp.setAttackDamage(42);

  ClapTrap tmp2(tmp);
  print ("Tmp2 energy points: " << tmp2.getEnergyPoints ());
  print ("Tmp2 hit points: " << tmp2.getEnergyPoints ());
  print ("Tmp2 attack damage: " << tmp2.getAttackDamage ());
}
}
