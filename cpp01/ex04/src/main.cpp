#include <ios>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>

#include "utils.hpp"

bool	validade_args(int argc, char **argv)
{
	if (argc != 4 || !argv[1][0] || !argv[2][0] || !argv[3][0])
		return false;
	return (true);
}

bool	check_file_permissions(std::string input)
{
	std::string		output;
	std::fstream	input_file;
	std::fstream	output_file;

	output = input + ".replace";
	input_file.open(input.c_str(), std::ios_base::out | std::ios_base::in);
	output_file.open(output.c_str(), std::ios_base::out);
	return (input_file.is_open() && output_file.is_open());
}

int main(int argc, char **argv)
{
	std::string		input;
	std::string		output;

	input = argv[1];
	if (!validade_args(argc, argv))
		std::cerr << "Usage: ./sed <file> <string_to_remove> <string_to_add>" << "\n";
	else if (!check_file_permissions(input))
		std::cerr << "We dont have the need permissions of your file";

	std::ifstream		input_file;
	std::ofstream		output_file;
	std::stringstream	get_buffer;
	std::string			buffer;

	output = input + ".replace";
	input_file.open(input.c_str(), std::ios_base::in | std::ios_base::out);
	output_file.open(output.c_str(), std::ios_base::out);
	get_buffer << input_file.rdbuf();
	buffer = get_buffer.str();
	std::string		replaced;

	replaced = replace(buffer, argv[2], argv[3]);
	output_file << replaced;
}
