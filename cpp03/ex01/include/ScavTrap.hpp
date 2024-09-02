#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:

		/* Cannonical form */
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

};
