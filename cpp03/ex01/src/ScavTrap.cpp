#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap () : ClapTrap ()
{
  print ("ScavTrap default constructor called");
  this->setHitPoints (100);
  this->setEnergyPoints (50);
  this->setAttackDamage (20);
}

ScavTrap::ScavTrap (const ScavTrap &other)
{
  print ("ScavTrap copy constructor called");
  *this = other;
}

ScavTrap &
ScavTrap::operator= (const ScavTrap &other)
{
  print ("ScavTrap assigment operator called");
  if (this != &other)
    {
      this->setName (other.getName ());
      this->setHitPoints (other.getHitPoints ());
      this->setEnergyPoints (other.getEnergyPoints ());
      this->setAttackDamage (other.getAttackDamage ());
    }
  return *this;
}

ScavTrap::~ScavTrap () { print ("ScavTrap destructor called"); }

ScavTrap::ScavTrap (std::string name) : ClapTrap (name)
{
  print ("ScavTrap name constructor called");
  this->setHitPoints (100);
  this->setEnergyPoints (50);
  this->setAttackDamage (20);
}

void
ScavTrap::guardGate ()
{
  print ("ScavTrap " << this->getName ()
                     << " have enterred in Gate keeper mode");
}

void
ScavTrap::attack (const std::string &target)
{
  print ("ScavTrap " << this->getName () << " attack " << target << " causing "
                     << this->getAttackDamage () << " points of damage!");
}
