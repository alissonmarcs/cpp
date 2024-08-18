#include "Zombie.hpp"

int main(void)
{
	Zombie *one = new Zombie("heap1");
	Zombie two("stack1");

	two.announce();
	one->announce();
	delete one;

	one = newZombie("heap2");
	one->announce();
	randomChump("stack2");
	delete one;
}