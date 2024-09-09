#pragma once

#include <string>

class Brain
{
private:
	std::string ideas[100];

public:
	/* Canonical form */
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

};
