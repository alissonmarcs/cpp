#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		int		getEnergyPoints() const;
		void	setEnergyPoints(int amount);
		int		getHitPoints() const;
		void	setHitPoints(int amount);
		int		getAttackDamage() const;
		void	setAtackDamage(int amount);

	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
	
};

#define printl(s) std::cout << s << std::endl;
