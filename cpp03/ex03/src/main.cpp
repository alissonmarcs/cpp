#include <iomanip>
#include "DiamondTrap.hpp"


namespace Tests
{
void
TestDefaultConstructor ()
{
  DiamondTrap diamon;

  print (std::setw (28) << std::left << "DiamondTrap Name: " << diamon.getName ());
  print (std::setw (28) << std::left
                        << "DiamondTrap Hit points: " << diamon.getHitPoints ());
  print (std::setw (28) << std::left << "DiamondTrap Energy points: "
                        << diamon.getEnergyPoints ());
  print (std::setw (28) << std::left << "DiamondTrap Attack damage: "
                        << diamon.getAttackDamage ());
}

void
TestNameConstructor ()
{
  DiamondTrap diamon ("any name here");

  print (std::setw (28) << std::left << "DiamondTrap Name: " << diamon.getName ());
  print (std::setw (28) << std::left
                        << "DiamondTrap Hit points: " << diamon.getHitPoints ());
  print (std::setw (28) << std::left << "DiamondTrap Energy points: "
                        << diamon.getEnergyPoints ());
  print (std::setw (28) << std::left << "DiamondTrap Attack damage: "
                        << diamon.getAttackDamage ());
}

void
TestAssigmentOperator ()
{
  DiamondTrap awesome ("awesome");
  DiamondTrap any ("any");

  awesome.setHitPoints (2);
  awesome.setEnergyPoints (2);
  awesome.setAttackDamage (2);
  any = awesome;

  print (std::setw (28) << std::left << "DiamondTrap Name: " << any.getName ());
  print (std::setw (28) << std::left
                        << "DiamondTrap Hit points: " << any.getHitPoints ());
  print (std::setw (28) << std::left << "DiamondTrap Energy points: "
                        << any.getEnergyPoints ());
  print (std::setw (28) << std::left << "DiamondTrap Attack damage: "
                        << any.getAttackDamage ());
}

void
TestCopyConstructor ()
{
  DiamondTrap awesome ("awesome");

  awesome.setHitPoints (7);
  awesome.setEnergyPoints (7);
  awesome.setAttackDamage (7);
  DiamondTrap copy (awesome);

  print (std::setw (28) << std::left << "DiamondTrap Name: " << copy.getName ());
  print (std::setw (28) << std::left
                        << "DiamondTrap Hit points: " << copy.getHitPoints ());
  print (std::setw (28) << std::left << "DiamondTrap Energy points: "
                        << copy.getEnergyPoints ());
  print (std::setw (28) << std::left << "DiamondTrap Attack damage: "
                        << copy.getAttackDamage ());
}

void TestDiamondTrapSpecifics ()
{
  DiamondTrap d ("i am alisson");

  print (std::setw (28) << std::left << "DiamondTrap Name: " << d.getName ());
  print (std::setw (28) << std::left
                        << "DiamondTrap Hit points: " << d.getHitPoints ());
  print (std::setw (28) << std::left << "DiamondTrap Energy points: "
                        << d.getEnergyPoints ());
  print (std::setw (28) << std::left << "DiamondTrap Attack damage: "
                        << d.getAttackDamage ());

  d.attack ("boss");
  d.whoAmI ();
}
}

int main(void)
{
  print ("\n\n\t\tTesting Default Constructor\n");
  Tests::TestDefaultConstructor ();

  print ("\n\n\t\tTesting Name Constructor\n");
  Tests::TestNameConstructor ();

  print ("\n\n\t\tTesting Assigment Operator\n");
  Tests::TestAssigmentOperator ();

  print ("\n\n\t\tTesting Copy Constructor\n");
  Tests::TestCopyConstructor ();

  print ("\n\n\t\tTesting DiamondTrap specifics\n");
  Tests::TestDiamondTrapSpecifics ();
  return 0;
}
