#pragma once

#include <iostream>
#include "PhoneBook/PhoneBook.hpp"

#define CMD_ADD "ADD"
#define CMD_SEARCH "SEARCH"
#define CMD_EXIT "EXIT"

class UserInterface
{
	PhoneBook	*phoneBook;

	void add(void);
	void search(void);
	std::string prompt(const char *message);
public:
	~UserInterface(void);
	void start(PhoneBook *PhoneBook);
};
