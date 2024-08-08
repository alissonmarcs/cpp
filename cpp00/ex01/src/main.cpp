#include "Contact.hpp"
#include "PhoneBook.hpp"

#include <iostream>
#include <cstdio>

bool	end = false;

void	prompt(std::string &input, PhoneBook &book)
{
	if (!input.compare("ADD"))
		book.add();
	else if (!input.compare("SEARCH"))
		std::cout << "The command is: " << input << '\n';
	else if (!input.compare("EXIT"))
	{
		std::cout << "Bye" << '\n';
		end = true;
	}
	else
		std::cout << "Unknow command: " << input << '\n';
}

int		main(void)
{
	PhoneBook		book;
	std::string		input = "ADD";

	

	// prompt(inp, book);
	// Contact tmp;;

	// std::cin >> tmp;
	
	// std::cout << tmp.getFirstName() << '\n';
	// std::cout << tmp.getLastName() << '\n';
	// std::cout << tmp.getDarkestSecret() << '\n';
	// std::cout << tmp.getPhoneNumber() << '\n';
	// std::cout << tmp.getNickName() << '\n';
}