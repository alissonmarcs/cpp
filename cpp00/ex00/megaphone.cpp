#include <iostream>
#include <cctype>

std::string up_case(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		str[i] = std::toupper(str[i]);
	return (str);
}

int		main(int argc, char **argv)
{

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argv[1][0] != '\0')
	{
		for (int i = 1; argv[i]; i++)
			std::cout << up_case(argv[i]);
		std::cout << std::endl;
	}
	return 0;
}
