#pragma once

#include <string>

class Weapon
{
	private:
		std::string		type;

	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string&	getType(void) const;
		void				setType(std::string type);
};

