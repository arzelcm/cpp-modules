#include <iostream>
#include <cstdlib> 
#include "UserInterface.hpp"

UserInterface::~UserInterface(void)
{
	return;
}

static std::string promptFun(const char *message)
{
	std::string value;

	while (value.empty() && !std::cin.eof())
	{
		std::cout << message;
		std::getline(std::cin, value);
	}
	return value;
}

static void strUpperCase(std::string *str)
{
	for (std::string::size_type i = 0; i < str->size(); i++)
		(*str)[i] = toupper((*str)[i]);
}

void UserInterface::start(PhoneBook *phoneBook)
{
	std::string cmd;

	this->phoneBook = phoneBook;
	std::cout << "Starting UI" << std::endl;
	while (cmd != CMD_EXIT && !std::cin.eof())
	{
		std::cout << "Write a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}
		strUpperCase(&cmd);
		if (cmd == CMD_ADD || cmd == "A")
			this->add();
		else if (cmd == CMD_SEARCH || cmd == "S")
			this->search();
		else if (!cmd.empty())
			std::cout << "Command \"" << cmd << "\" not found. " << std::endl;
		std::cout << std::endl;
	}
	std::cout << "Bye ;)" << std::endl;
}

void UserInterface::add(void)
{
	Contact contact;
	std::cout << std::endl
			  << "Creating contact, introduce details."
			  << std::endl;
	contact.firstName = promptFun("First name: ");
	contact.lastName = promptFun("Last name: ");
	contact.nickName = promptFun("Nick name: ");
	contact.phoneNumber = promptFun("Phone number: ");
	contact.darkestSecret = promptFun("Darkest secret: ");
	this->phoneBook->addContact(&contact);
}

void UserInterface::search(void)
{
	int	choice;

	choice = -1;
	this->phoneBook->listContacts();
	if (this->phoneBook->contacts_size > 0)
	{
		while (choice < 0 || choice >= this->phoneBook->contacts_size)
			choice = atoi(promptFun("Choose your fighter: ").c_str());
		if (!std::cin.eof())
			this->phoneBook->contacts[choice].show();
	}
}
