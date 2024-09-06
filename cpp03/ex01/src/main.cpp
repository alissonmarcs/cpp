#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iomanip>

namespace Tests
{
void
TestDefaultConstructor ()
{
  ScavTrap scav;

  print (std::setw (30) << std::left << "scav Name: " << scav.getName ());
  print (std::setw (30) << std::left
                        << "scav Hit Points: " << scav.getHitPoints ());
  print (std::setw (30) << std::left
                        << "scav Energy Points: " << scav.getEnergyPoints ());
  print (std::setw (30) << std::left
                        << "scav Attack Damage: " << scav.getAttackDamage ());
}

void
TestNameConstructor ()
{
  ScavTrap scav ("senhor pedro");

  print (std::setw (30) << std::left << "scav Name: " << scav.getName ());
  print (std::setw (30) << std::left
                        << "scav Hit Points: " << scav.getHitPoints ());
  print (std::setw (30) << std::left
                        << "scav Energy Points: " << scav.getEnergyPoints ());
  print (std::setw (30) << std::left
                        << "scav Attack Damage: " << scav.getAttackDamage ());
}

void
TestCopyConstructor ()
{
  ScavTrap scav ("carla");
  scav.setHitPoints (3);
  scav.setEnergyPoints (3);
  scav.setAttackDamage (3);
  ScavTrap scavCopy (scav);

  print (std::setw (30) << std::left << "scavCopy Name: " << scavCopy.getName ());
  print (std::setw (30) << std::left
                        << "scavCopy Hit Points: " << scavCopy.getHitPoints ());
  print (std::setw (30) << std::left << "scavCopy Energy Points: "
                        << scavCopy.getEnergyPoints ());
  print (std::setw (30) << std::left << "scavCopy Attack Damage: "
                        << scavCopy.getAttackDamage ());
}

void
TestAssignmentOperator ()
{
  ScavTrap scav ("carla");
  ScavTrap scavCopy ("simone");

  scav.setHitPoints (3);
  scav.setEnergyPoints (3);
  scav.setAttackDamage (3);
  scavCopy = scav;
  print (std::setw (30) << std::left << "scavCopy Name: " << scavCopy.getName ());
  print (std::setw (30) << std::left
                        << "scavCopy Hit Points: " << scavCopy.getHitPoints ());
  print (std::setw (30) << std::left << "scavCopy Energy Points: "
                        << scavCopy.getEnergyPoints ());
  print (std::setw (30) << std::left << "scavCopy Attack Damage: "
                        << scavCopy.getAttackDamage ());
}

void
TestScavTrapSpecifics ()
{
  ScavTrap scav ("carla");

  scav.guardGate ();
  scav.attack ("enemy");
}
}

int
main ()
{
  print ("\n\n\t\tTesting Default Constructor\n");
  Tests::TestDefaultConstructor ();

  print ("\n\n\t\tTesting Name Constructor\n");
  Tests::TestNameConstructor ();

  print ("\n\n\t\tTesting Copy Constructor\n");
  Tests::TestCopyConstructor ();

  print ("\n\n\t\tTesting Assignment Operator\n");
  Tests::TestAssignmentOperator ();

  print ("\n\n\t\tTesting ScavTrap specifics\n");
  Tests::TestScavTrapSpecifics ();

  return 0;
}
