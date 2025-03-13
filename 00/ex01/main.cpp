#include <iostream>
#include <cstdlib>
#include "PhoneBook/PhoneBook.hpp"
#include "UserInterface/UserInterface.hpp"

int	main(void)
{
	PhoneBook		phoneBook;
	UserInterface	ui;

	ui.start(&phoneBook);
	return(EXIT_SUCCESS);
}