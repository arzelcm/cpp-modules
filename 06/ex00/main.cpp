#include <iostream>
#include "ScalarConverter/ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << "< Casting \"" << argv[i] << "\" >" << std::endl;
			ScalarConverter::convert(argv[i]);
			std::cout << std::endl;
		}
		return 0;
	}
	else
	{
		std::cout << "Missing args..." << std::endl;
		return 1;
	}
}