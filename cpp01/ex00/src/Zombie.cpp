#include <string>
#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie (std::string name)
{
	std::cout << name << " was born" << std::endl;
	this->name = name;	
}	

Zombie::~Zombie(void)
{
	std::cout << this->name << " is dead" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}