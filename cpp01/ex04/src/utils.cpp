#include "utils.hpp"

std::string			replace(std::string str, std::string remove, std::string add)
{
	std::string		before, after;
	size_t			pos;

	if (str.empty() || remove.empty() || add.empty())
		return before;
	pos = str.find(remove);
	while (pos != std::string::npos)
	{
		before = str.substr(0, pos);
		after = str.substr(pos + remove.size());
		str = before + add + after;
		pos = str.find(remove);
	}
	return str;
}
