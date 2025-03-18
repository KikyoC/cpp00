#include <iostream>

int main(int argc, char **argv)
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j]; j++) {
				std::cout << (char)std::toupper(argv[i][j]);
			}
			if (i + 1 < argc)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}
