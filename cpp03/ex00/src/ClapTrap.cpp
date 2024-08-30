#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("guest"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &
ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAtackDamage(other.getAttackDamage());
	}
	return *this;
}

std::string
ClapTrap::getName() const
{
	return _name;
}

void
ClapTrap::setName(std::string name)
{
	_name = name;
}

void
ClapTrap::attack(const std::string &target)
{
	if (getHitPoints() <= 0)
		std::cout << "ClapTrap " << _name << " is dead and can't attack!" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "ClapTrap " << _name << " is out of energy and can't attack!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
}

void
ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
}

void
ClapTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0)
		std::cout << "ClapTrap " << _name << " is dead and can't be repaired!" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "ClapTrap " << _name << " is out of energy and can't be repaired!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points!" << std::endl;
		_energyPoints -= 1;
		_hitPoints += amount;		
	}
}

int
ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

void
ClapTrap::setHitPoints(int amount)
{
		_hitPoints = amount;
}

int
ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

void
ClapTrap::setEnergyPoints(int amount)
{
	if (amount > 0)	
		_energyPoints = amount;
}

void
ClapTrap::setAtackDamage(int amount)
{
	if (amount > 0)	
		_attackDamage = amount;
}

int
ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}


ClapTrap::~ClapTrap() {}
