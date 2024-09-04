#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap()
{
	print("FragTrap default constructor called");
	this->setName("guest");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	print("FragTrap name constructor called");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other)
{
	print("FragTrap copy constructor called");
	*this = other;
}

FragTrap &
FragTrap::operator=(const FragTrap &other)
{
	print("FlagTrap assigment operator called");
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	return *this;
}

FragTrap::~FragTrap()
{
	print("FragTrap destructor called");
}

void
FragTrap::highFivesGuys()
{
	if (getHitPoints() <= 0)
		print("FragTrap " << getName() << " is dead and can't request a high five!");
	else if (getEnergyPoints() <= 0)
		print("FragTrap " << getName() << " is out of energy and can't request a high five!");
	else
		print("FragTrap " << getName() << " requests a high five!");
}
