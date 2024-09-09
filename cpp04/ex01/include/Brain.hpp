#pragma once

#include <string>

class Brain
{
private:
	std::string _ideas[100];

public:
	/* Canonical form */
	Brain();
	Brain(const Brain &other);
	Brain & operator=(const Brain &other);
	~Brain();

	/* Subject */
	void setIdea(const std::string &idea, int index);
	std::string getIdea(int index) const;

};
