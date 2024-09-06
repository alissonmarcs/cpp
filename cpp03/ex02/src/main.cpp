#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iomanip>

namespace Tests
{
void
TestDefaultConstructor ()
{
  FragTrap frag;

  print (std::setw (28) << std::left << "FragTrap Name: " << frag.getName ());
  print (std::setw (28) << std::left
                        << "FragTrap Hit points: " << frag.getHitPoints ());
  print (std::setw (28) << std::left << "FragTrap Energy points: "
                        << frag.getEnergyPoints ());
  print (std::setw (28) << std::left << "FragTrap Attack damage: "
                        << frag.getAttackDamage ());
}

void
TestNameConstructor ()
{
  FragTrap frag ("any name here");

  print (std::setw (28) << std::left << "FragTrap Name: " << frag.getName ());
  print (std::setw (28) << std::left
                        << "FragTrap Hit points: " << frag.getHitPoints ());
  print (std::setw (28) << std::left << "FragTrap Energy points: "
                        << frag.getEnergyPoints ());
  print (std::setw (28) << std::left << "FragTrap Attack damage: "
                        << frag.getAttackDamage ());
}

void
TestAssigmentOperator ()
{
  FragTrap awesome ("awesome");
  FragTrap any ("any");

  awesome.setHitPoints (2);
  awesome.setEnergyPoints (2);
  awesome.setAttackDamage (2);
  any = awesome;

  print (std::setw (28) << std::left << "FragTrap Name: " << any.getName ());
  print (std::setw (28) << std::left
                        << "FragTrap Hit points: " << any.getHitPoints ());
  print (std::setw (28) << std::left << "FragTrap Energy points: "
                        << any.getEnergyPoints ());
  print (std::setw (28) << std::left << "FragTrap Attack damage: "
                        << any.getAttackDamage ());
}

void
TestCopyConstructor ()
{
  FragTrap awesome ("awesome");

  awesome.setHitPoints (7);
  awesome.setEnergyPoints (7);
  awesome.setAttackDamage (7);
  FragTrap copy (awesome);

  print (std::setw (28) << std::left << "FragTrap Name: " << copy.getName ());
  print (std::setw (28) << std::left
                        << "FragTrap Hit points: " << copy.getHitPoints ());
  print (std::setw (28) << std::left << "FragTrap Energy points: "
                        << copy.getEnergyPoints ());
  print (std::setw (28) << std::left << "FragTrap Attack damage: "
                        << copy.getAttackDamage ());
}

void
TestHighFivesGuys ()
{
  FragTrap awesome ("awesome");

  awesome.highFivesGuys ();
  awesome.setHitPoints (0);
  awesome.highFivesGuys ();
  awesome.setHitPoints (1);
  awesome.setEnergyPoints (0);
  awesome.highFivesGuys ();
}

}

int
main (void)
{

  print ("\n\n\t\tTesting Default Constructor\n");
  Tests::TestDefaultConstructor ();

  print ("\n\n\t\tTesting Name Constructor\n");
  Tests::TestNameConstructor ();

  print ("\n\n\t\tTesting Assigment Operator\n");
  Tests::TestAssigmentOperator ();

  print ("\n\n\t\tTesting Copy Constructor\n");
  Tests::TestCopyConstructor ();

  print ("\n\n\t\tTesting High Fives Guys\n");
  Tests::TestHighFivesGuys ();

  print ("test only");
  return 0;
}
