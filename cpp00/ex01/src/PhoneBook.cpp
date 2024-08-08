#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iomanip>

PhoneBook::PhoneBook() {
	// std::cout << "PhoneBook constructor called\n";
	index = 0;
}

PhoneBook::~PhoneBook() {
	// std::cout << "PhoneBook destructor called\n";
}

void PhoneBook::add() {
	std::cin >> this->contacts[index];
	index++;
}

void PhoneBook::search() {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nick Name" << "|\n";
	for (int i = 0; i < index; i++) {
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << utils::truncateString(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << utils::truncateString(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << utils::truncateString(this->contacts[i].getNickName()) << "|\n";
	}
}
