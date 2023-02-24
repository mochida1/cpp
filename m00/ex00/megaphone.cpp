#include <iostream>
#include <string>

int	megaphone(int argc, char *argv[])
{
	std::string	str;
	char		c;
	size_t		i;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int (i) = 1; i < argc; i++)
		str.append(argv[i]);
	for (i = 0; i < str.length(); i++)
	{
		c = toupper(str[i]);
		std::cout << c;
	}
	std::cout << std::endl;
	return (0);
}

int	main (int argc, char *argv[])
{
	return(megaphone(argc, argv));
}
