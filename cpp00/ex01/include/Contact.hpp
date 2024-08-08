#ifndef Contact_HPP
#define Contact_HPP

#include <string>
#include <iostream>

class	Contact {
private:
	std::string			FirstName;
	std::string			LastName;
	std::string			NickName;
	std::string			DarkestSecret;
	std::string			PhoneNumber;

public:
	Contact();
	~Contact();
	void			setFirstName(std::string name);
	void			setLastName(std::string name);
	void			setNickName(std::string name);
	void			setPhoneNumber(std::string number);
	void			setDarkestSecret(std::string name);
	std::string		getFirstName();
	std::string		getLastName();
	std::string		getNickName();
	std::string		getDarkestSecret();
	std::string		getPhoneNumber();
};

std::istream &operator>>(std::istream &input, Contact &contact);
#endif
