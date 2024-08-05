#include <iostream>
#include <cctype>

void	up_case(char *string)
{
	while (*string)
	{
		*string = std::toupper(*string);
		string++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else if (argv[1][0] != '\0')
	{
		for (int i = 1; argv[i]; i++)
		{
			up_case(argv[i]);
			std::cout << argv[i];
		}
		std::cout << '\n';
	}
	return 0;
}