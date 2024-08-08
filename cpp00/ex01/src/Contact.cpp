#include "Contact.hpp"

Contact::Contact() {
	std::cout << "Contact contructor called\n";
}

Contact::~Contact() {
	std::cout << "Contact destructor called\n";
}

void			Contact::setFirstName(std::string name) {
	this->FirstName = name;
}

void			Contact::setLastName(std::string name) {
	this->LastName = name;
}

void			Contact::setNickName(std::string nick) {
	this->NickName = nick;
}

void			Contact::setDarkestSecret(std::string secret) {
	this->DarkestSecret = secret;
}

void			Contact::setPhoneNumber(std::string number) {
	this->PhoneNumber = number;
}

std::string		Contact::getFirstName() {
	return this->FirstName;
}

std::string		Contact::getLastName() {
	return this->LastName;
}

std::string		Contact::getNickName() {
	return this->NickName;
}

std::string		Contact::getDarkestSecret() {
	return this->DarkestSecret;
}

std::string		Contact::getPhoneNumber() {
	return this->PhoneNumber;
}

std::istream &operator>>(std::istream &input, Contact &contact)
{
	std::string		string;

	std::cout << "Enter NickName: "; 
	std::cin >> string;
	contact.setNickName(string);
	std::cout << "Enter FirstName: ";
	std::cin >> string;
	contact.setFirstName(string);
	std::cout << "Enter LastName: ";
	std::cin >> string;
	contact.setLastName(string);
	std::cout << "Enter PhoneNumber: ";
	std::cin >> string;
	contact.setPhoneNumber(string);
	std::cout << "Enter DarkestSecret: ";
	std::cin >> string;
	contact.setDarkestSecret(string);
	return input;
}
