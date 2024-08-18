#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "PhoneBook.hpp"

namespace utils
{
	std::string truncateString(std::string input)
	{
		if (input.size() > 10)
				return (input.substr(0, 9) + ".");
		return input;
	}
	
	std::string getUserInput(std::string prompt)
	{
		std::string		input;

		std::cout << "Enter the " << prompt << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << '\n';
			exit(42);
		}
		if (input.empty())
		{
			std::cout << "Contact cant have empty fileds! Try again:\n";
			input = getUserInput(prompt);
		}
		return input;
	}

	int 		getContactIndex(int len)
	{
		int				index;
		std::string		input;

		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << '\n';
			exit(42);
		}
		index = input[0] - '0';
		if (input.size() != 1 || input[0] < '0' || input[0] > '7' || index >= len)
		{
			std::cout << "Invalid index, try again: ";
			index = getContactIndex(len);
		}
		return index;
	}

	bool		isNumber(std::string input)
	{
		for (size_t i = 0; i < input.size(); i++)
		{
			if (!std::isdigit(input[i]))
				return false;
		}
		return true;
	}

	std::string	getPhoneNumber()
	{
		std::string		input;

		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << '\n';
			exit(42);
		}
		if (!isNumber(input) || input.size() < 9)
		{
			std::cout << "Invalid phone number, try again: ";
			input = getPhoneNumber();
		}
		return input;
	}
}