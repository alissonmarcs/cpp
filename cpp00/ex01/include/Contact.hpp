#ifndef Contact_HPP
#define Contact_HPP

#include <string>
#include <iostream>

class	Contact
{
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
		std::string		getFirstName() const;
		std::string		getLastName() const;
		std::string		getNickName() const;
		std::string		getDarkestSecret() const;
		std::string		getPhoneNumber() const;
		bool			empty() const;
	};

std::istream &operator>>(std::istream &input, Contact &contact);
std::ostream &operator<<(std::ostream &output, Contact &contact);
#endif
