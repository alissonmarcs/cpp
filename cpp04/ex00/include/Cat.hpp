#pragma once

#include "Animal.hpp"
#include "Cat.hpp"

class Cat : public Animal
{
public:
	/* Canonical form */
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();

	/* Subject */
	void makeSound() const;
};
