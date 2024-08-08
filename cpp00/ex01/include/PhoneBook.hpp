#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include "Contact.hpp"

class	PhoneBook {
private:
	Contact			contacts[8];
	int				index;

public:
	PhoneBook();
	~PhoneBook();
	void		add();
	void		search();
	
};

#endif