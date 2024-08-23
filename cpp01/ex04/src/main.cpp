#include "utils.hpp"
#include <iostream>

int			main(int argc, char **argv)
{
	std::string		file_name, content, new_content;

	if (utils::validations(argc, argv))
	{
		file_name = argv[1];
		content = utils::get_file_content(file_name);
		new_content = utils::replace(content, argv[2], argv[3]);
		utils::write_file_content(file_name + ".replace", new_content);
	}
	else
	{
		std::cerr << "Invalid permision of files or invalid number of arguments";
		std::cerr << '\n';
	}
}
