#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"

#include <iostream>
#include <cstdio>
#include <cstdlib>

void	printOptions()
{
	std::cout << '\n';
	std::cout << "ADD\n";
	std::cout << "SEARCH\n";
	std::cout << "EXIT\n\n";
}

int		main()
{
	PhoneBook		book;
	std::string		input;

	while (input != "EXIT")
	{
		printOptions();
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if (feof(stdin) == 1)
		{
			std::cout << '\n';
			exit(42);
		}
		if (input == "ADD")	
			book.add();
		else if (input == "SEARCH")
			book.search();
	}
}