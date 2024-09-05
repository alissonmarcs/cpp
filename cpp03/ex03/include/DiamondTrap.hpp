#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:

		/* Canonical form */
		DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap();

		/* Subject */
		DiamondTrap(std::string name);
		void attack(const std::string &target);
		void whoAmI();
		std::string getName() const;
		void setName(std::string name);
		bool operator==(const DiamondTrap &object) const;
	private:
		std::string _name;
};
