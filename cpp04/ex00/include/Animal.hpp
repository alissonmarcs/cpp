#pragma once

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string _type;

public:
	/* Canonical form */
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	~Animal();

	/* Subject */
	Animal(std::string type);
	virtual void makeSound () const;
	std::string getType () const;
	void setType(std::string type);
};

#define print(s) std::cout << s << std::endl
