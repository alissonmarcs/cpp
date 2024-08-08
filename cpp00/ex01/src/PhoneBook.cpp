#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "PhoneBook constructor called\n";
	index = 0;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook destructor called\n";
}

void PhoneBook::add() {
	std::cin >> this->contacts[index];
	index++;
}
