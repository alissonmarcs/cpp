#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap () : ClapTrap (), ScavTrap (), FragTrap ()
{
  print ("DiamondTrap default constructor called");
  setEnergyPoints (50);
  this->DiamondTrap::setName ("guest");
  this->ClapTrap::setName (this->DiamondTrap::getName () + "_clap_name");
}

DiamondTrap::DiamondTrap (const DiamondTrap &other)
    : ClapTrap (other), ScavTrap (other), FragTrap (other)
{
  print ("DiamondTrap copy constructor called");
  *this = other;
}

DiamondTrap &
DiamondTrap::operator= (const DiamondTrap &other)
{
  print ("DiamondTrap assigment operator called");
  this->DiamondTrap::_name = other.DiamondTrap::_name;
  this->ClapTrap::_name = other.ClapTrap::_name;
  this->ClapTrap::_hitPoints = other.ClapTrap::_hitPoints;
  this->ClapTrap::_energyPoints = other.ClapTrap::_energyPoints;
  this->ClapTrap::_attackDamage = other.ClapTrap::_attackDamage;
  return *this;
}

DiamondTrap::~DiamondTrap () { print ("DiamondTrap destructor called"); }

void
DiamondTrap::attack (const std::string &target)
{
  this->ScavTrap::attack (target);
}

void
DiamondTrap::whoAmI ()
{
  print ("DiamondTrap name: " << this->DiamondTrap::getName ());
  print ("ClapTrap name: " << this->ClapTrap::getName ());
}

DiamondTrap::DiamondTrap (std::string name)
    : ClapTrap (name), ScavTrap (name), FragTrap (name)
{
  print ("DiamondTrap name constructor called");
  setEnergyPoints (50);
  this->DiamondTrap::setName (name);
  this->ClapTrap::setName (this->DiamondTrap::getName () + "_clap_name");
}

std::string
DiamondTrap::getName () const
{
  return this->DiamondTrap::_name;
}

void
DiamondTrap::setName (std::string name)
{
  this->DiamondTrap::_name = name;
  this->ClapTrap::_name = name + "_clap_name";
}
