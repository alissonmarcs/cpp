#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
public:
	/* Canonical form */
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();

	/* Subject */
	void makeSound() const;
};
