#include <string>

namespace utils
{
	std::string truncateString(std::string input)
	{
		if (input.size(10) > 10)
			return (input.substr(0, 9) + ".");
		return (input);
	}
}