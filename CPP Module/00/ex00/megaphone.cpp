#include <iostream>
#include <cctype>

void printToUpperCase(char *str);

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "BEEPS! EEEEEEEEEEEEEEEEEEEEE" << std::endl;
	for (int i = 1; i < argc; i++)
		printToUpperCase(argv[i]);
	std::cout << std::endl;
}

void printToUpperCase(char *str)
{
	int i = 0;

	while (str[i])
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
	std::cout << str;
}
