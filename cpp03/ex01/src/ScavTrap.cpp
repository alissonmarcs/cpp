#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap () : ClapTrap ()
{
  print ("ScavTrap default constructor called");
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
}

ScavTrap::ScavTrap (const ScavTrap &other) : ClapTrap (other)
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
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
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
  if (this->getHitPoints () <= 0)
    print ("ScavTrap " << this->getName () << " is dead and can't attack!");
  else if (this->getEnergyPoints () <= 0)
    print ("ScavTrap " << this->getName () << " is out of energy and can't attack!");
  else
    print ("ScavTrap " << this->getName () << " attack " << target << " causing "
                     << this->getAttackDamage () << " points of damage!");
  _energyPoints -= 1;
}
