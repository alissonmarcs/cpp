#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* z;

	if (N <= 0 || name.empty())
		return NULL;
	z = new Zombie[N];
	for (int i = 0; i < N; i++)
		z[i].setName(name);
	return z;
}
