#include <iostream>
#include <cstdlib>
#include "Harl/Harl.hpp"

int main(int argc, char *argv[])
{
	Harl harl;
	int complainI;
	std::string *complains;

	complainI = 0;
	if (argc != 2)
	{
		std::cout << "Illegal use. Must exec with 1 parameter." << std::endl;
		return EXIT_FAILURE;
	}
	complains = harl.getComplains();
	while (complainI < COMPLAINS_AMOUNT && complains[complainI] != argv[1])
		complainI++;
	switch (complainI)
	{
	case DEBUG:
		std::cout << "[ " << argv[1] << " ]" << std::endl;
		harl.complain(complains[DEBUG]);
		harl.complain(complains[INFO]);
		harl.complain(complains[WARNING]);
		harl.complain(complains[ERROR]);
		break;
	case INFO:
		std::cout << "[ " << argv[1] << " ]" << std::endl;
		harl.complain(complains[INFO]);
		harl.complain(complains[WARNING]);
		harl.complain(complains[ERROR]);
		break;
	case WARNING:
		std::cout << "[ " << argv[1] << " ]" << std::endl;
		harl.complain(complains[WARNING]);
		harl.complain(complains[ERROR]);
		break;
	case ERROR:
		std::cout << "[ " << argv[1] << " ]" << std::endl;
		harl.complain(complains[ERROR]);
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	return (EXIT_SUCCESS);
}

// int main(int argc, char *argv[])
// {
// 	Harl harl;
// 	int	complainI;
// 	std::string	*complains;

// 	if (argc != 2)
// 	{
// 		std::cout << "Illegal use. Must exec with 1 parameter." << std::endl;
// 		return EXIT_FAILURE;
// 	}
// 	complains = harl.getComplains();
// 	while (complainI < COMPLAINS_AMOUNT && complains[complainI] != argv[1])
// 		complainI++;
// 	if (complainI == COMPLAINS_AMOUNT)
// 		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
// 	else
// 		std::cout << "[ " << argv[1] << " ]" << std::endl;
// 	for (int i = complainI; i < COMPLAINS_AMOUNT; i++)
// 		harl.complain(complains[i]);
// 	return (EXIT_SUCCESS);
// }