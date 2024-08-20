#pragma once

namespace utils
{
	std::string		replace(std::string str, std::string remove, std::string add);
	bool			check_args(int argc, char **argv);
	bool			check_file_permissions(std::string input);
	bool			validations(int argc, char **argv);
	std::string		get_file_content(std::string name);
	void			write_file_content(std::string name, std::string content);
}
