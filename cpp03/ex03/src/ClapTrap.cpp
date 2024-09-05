#include "ClapTrap.hpp"

ClapTrap::ClapTrap ()
    : _name ("guest"), _hitPoints (10), _energyPoints (10), _attackDamage (0)
{
  print ("ClapTrap default constructor called droga");
}

ClapTrap::ClapTrap (std::string name)
    : _name (name), _hitPoints (10), _energyPoints (10), _attackDamage (0)
{
  print ("ClapTrap name constructor called");
}

ClapTrap::ClapTrap (const ClapTrap &other)
{
  print ("ClapTrap copy constructor called");
  *this = other;
}

ClapTrap &
ClapTrap::operator= (const ClapTrap &other)
{
  print ("ClapTrap assigment operator called");
  if (this != &other)
    {
      this->setName (other.getName ());
      this->setHitPoints (other.getHitPoints ());
      this->setEnergyPoints (other.getEnergyPoints ());
      this->setAttackDamage (other.getAttackDamage ());
    }
  return *this;
}

std::string
ClapTrap::getName () const
{
  return this->ClapTrap::_name;
}

void
ClapTrap::setName (std::string name)
{
  _name = name;
}

void
ClapTrap::attack (const std::string &target)
{
  if (getHitPoints () <= 0)
    print ("ClapTrap " << getName () << " is dead and can't attack!");
  else if (getEnergyPoints () <= 0)
    print ("ClapTrap " << getName () << " is out of energy and can't attack!");
  else
    {
      print ("ClapTrap " << getName () << " attacks " << target << ", causing "
                         << getAttackDamage () << " points of damage!");
      _energyPoints -= 1;
    }
}

void
ClapTrap::takeDamage (unsigned int amount)
{
  print ("ClapTrap " << getName () << " takes " << amount
                     << " points of damage!");
  _hitPoints -= amount;
}

void
ClapTrap::beRepaired (unsigned int amount)
{
  if (getHitPoints () <= 0)
    print ("ClapTrap " << getName () << " is dead and can't be repaired!");
  else if (getEnergyPoints () <= 0)
    print ("ClapTrap " << getName ()
                       << " is out of energy and can't be repaired!");
  else
    {
      print ("ClapTrap " << getName () << " is repaired by " << amount
                         << " points!");
      _energyPoints -= 1;
      _hitPoints += amount;
    }
}

int
ClapTrap::getHitPoints () const
{
  return _hitPoints;
}

void
ClapTrap::setHitPoints (int amount)
{

  if (amount >= 0)
    _hitPoints = amount;
  else
    print ("ClapTrap hit points can't be negative! Previous value kept.");
}

int
ClapTrap::getEnergyPoints () const
{
  return _energyPoints;
}

void
ClapTrap::setEnergyPoints (int amount)
{
  if (amount >= 0)
    _energyPoints = amount;
  else
    print ("ClapTrap energy points can't be negative! Previous value kept.");
}

void
ClapTrap::setAttackDamage (int amount)
{
  if (amount >= 0)
    _attackDamage = amount;
  else
    print ("ClapTrap attack damage can't be negative! Previous value kept.");
}

int
ClapTrap::getAttackDamage () const
{
  return _attackDamage;
}

ClapTrap::~ClapTrap () { print ("ClapTrap destructor called"); }
