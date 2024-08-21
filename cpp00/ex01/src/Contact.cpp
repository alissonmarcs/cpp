#include "Contact.hpp"
#include "utils.hpp"

#include <iomanip>

Contact::Contact() {}

Contact::~Contact() {}

void			Contact::setFirstName(std::string name)
{
	this->FirstName = name;
}

void			Contact::setLastName(std::string name)
{
	this->LastName = name;
}

void			Contact::setNickName(std::string nick)
{
	this->NickName = nick;
}

void			Contact::setDarkestSecret(std::string secret)
{
	this->DarkestSecret = secret;
}

void			Contact::setPhoneNumber(std::string number)
{
	this->PhoneNumber = number;
}

std::string		Contact::getFirstName() const
{
	return this->FirstName;
}

std::string		Contact::getLastName() const
{
	return this->LastName;
}

std::string		Contact::getNickName() const
{
	return this->NickName;
}

std::string		Contact::getDarkestSecret() const
{
	return this->DarkestSecret;
}

std::string		Contact::getPhoneNumber() const
{
	return this->PhoneNumber;
}

bool			Contact::empty() const
{
	return this->FirstName.empty();
}

std::istream &operator>>(std::istream &input, Contact &contact)
{

	std::string		string;

	string = utils::getUserInput("NickName");
	contact.setNickName(string);
	string = utils::getUserInput("FirstName");
	contact.setFirstName(string);
	string = utils::getUserInput("LastName");
	contact.setLastName(string);
	std::cout << "Enter the PhoneNumber: ";
	string = utils::getPhoneNumber();
	contact.setPhoneNumber(string);
	string = utils::getUserInput("DarkestSecret");
	contact.setDarkestSecret(string);
	return input;
}

std::ostream &operator<<(std::ostream &output, Contact &contact)
{
	output << std::left << std::setw(18) <<
	"NickName: " << contact.getNickName() << '\n';
	output << std::left << std::setw(18) <<
	"FirstName: " << contact.getFirstName() << '\n';
	output << std::left << std::setw(18) <<
	"LastName: " << contact.getLastName() << '\n';
	output << std::left << std::setw(18) <<
	"PhoneNumber: " << contact.getPhoneNumber() << '\n';
	output << std::left << std::setw(18) <<
	"DarkestSecret: " << contact.getDarkestSecret() << std::endl;
	return output;
}
