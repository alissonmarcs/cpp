#pragma once

#include <string>

class Zombie
{
	private:
		std::string		name;

	public:
		Zombie(void);
		~Zombie(void);
		void			announce(void);
		void			setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);
