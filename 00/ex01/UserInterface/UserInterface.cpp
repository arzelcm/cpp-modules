#include <iostream>
#include <cstdlib> 
#include "UserInterface.hpp"

UserInterface::~UserInterface(void)
{
	return;
}

std::string UserInterface::promptFun(const char *message)
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
		else if (!cmd.empty() && cmd != CMD_EXIT)
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
	contact.setFirstName(promptFun("First name: "));
	contact.setLastName(promptFun("Last name: "));
	contact.setNickName(promptFun("Nick name: "));
	contact.setPhoneNumber(promptFun("Phone number: "));
	contact.setDarkestSecret(promptFun("Darkest secret: "));
	this->phoneBook->addContact(&contact);
}

void UserInterface::search(void)
{
	this->phoneBook->listContacts();
	this->phoneBook->searchContact();
}
