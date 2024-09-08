#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

namespace Tests
{
	void Subject()
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	void makeSound()
	{
		Cat c;
		Dog d;
		Animal a;

		c.makeSound();
		d.makeSound();
		a.makeSound();
	}

	void WrongMakeSound()
	{
		WrongCat c;
		WrongAnimal a;

		c.makeSound();
		a.makeSound();
	}
}

int main()
{
	print ("\n\n\t\tCat and Dog must inherite from Animal and overwrite makeSound()\n");
	Tests::makeSound();

	print ("\n\n\t\tWrongCat must inherite from WrongAnimal, but should not overwrite makeSound()\n");
	Tests::WrongMakeSound();

	print ("\n\n\t\tSubject Test\n");
	Tests::Subject();

	return 0;

}
