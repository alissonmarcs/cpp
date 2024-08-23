#ifndef UTILS_HPP
#define UTILS_HPP

namespace utils
{
	std::string truncateString(std::string input);
	std::string getUserInput(std::string prompt);
	int 		getContactIndex(int len);
	bool		isNumber(std::string input);
	std::string	getPhoneNumber();
}

#endif
