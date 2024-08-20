#include <fstream>
#include <sstream>

namespace utils
{
	std::string		replace(std::string str, std::string remove, std::string add)
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
			pos = str.find(remove, pos + remove.size());
		}
		return str;
	}

	bool			check_args(int argc, char **argv)
	{
		if (argc != 4 || !argv[1][0] || !argv[2][0] || !argv[3][0])
			return false;
		return (true);
	}

	bool			check_file_permissions(std::string input)
	{
		std::string		output;
		std::fstream	input_file;
		std::fstream	output_file;

		output = input + ".replace";
		input_file.open(input.c_str(), std::ios_base::out | std::ios_base::in);
		output_file.open(output.c_str(), std::ios_base::out);
		return (input_file.is_open() && output_file.is_open());
	}

	bool			validations(int argc, char **argv)
	{
		std::string		input;

		if (!check_args(argc, argv))
			return false;
		input = argv[1];
		if (!check_file_permissions(input))
			return false;
		return true;
	}

	std::string		get_file_content(std::string name)
	{
		std::fstream			file;
		std::stringstream		get_buffer;

		file.open(name.c_str(), std::ios_base::in);
		get_buffer << file.rdbuf();
		return get_buffer.str();
	}

	void			write_file_content(std::string name, std::string content)
	{
		std::fstream		file;

		file.open(name.c_str(), std::ios_base::out);
		file << content;
	}
}


