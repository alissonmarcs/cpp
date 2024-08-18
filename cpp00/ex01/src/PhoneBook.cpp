#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook()
{
	this->current = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::add()
{
	if (this->current == 8)
		this->current = 0;
	std::cin >> this->contacts[this->current];
	this->current++;
}

void PhoneBook::search() 
{
	int		len;
	
	if (contacts[0].empty())
	{
		std::cout << "PhoneBook is empty\n";
		return;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nick Name" << "|\n";
	for (len = 0; len < 8; len++)
	{
		if (contacts[len].empty())
			break;
		std::cout << std::setw(10) << len << "|";
		std::cout << std::setw(10) <<
		utils::truncateString(this->contacts[len].getFirstName()) << "|";
		std::cout << std::setw(10) <<
		utils::truncateString(this->contacts[len].getLastName()) << "|";
		std::cout << std::setw(10) <<
		utils::truncateString(this->contacts[len].getNickName()) << "|\n";
	}
	std::cout << "Enter index: ";
	int index = utils::getContactIndex(len);
	std::cout << this->contacts[index];
}
