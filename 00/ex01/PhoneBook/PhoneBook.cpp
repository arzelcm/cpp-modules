#include <iostream>
#include <sstream>
#include "PhoneBook.hpp"
#include "UserInterface/UserInterface.hpp"

PhoneBook::PhoneBook(void)
{
	this->last_contact = -1;
	this->contacts_size = 0;
	return;
}

void PhoneBook::addContact(Contact *newContact)
{
	Contact *contact;
	if (this->last_contact == PHONE_BOOK_MAX_CONTACTS - 1)
		this->last_contact = 0;
	else
		this->last_contact++;
	if (this->contacts_size == PHONE_BOOK_MAX_CONTACTS)
		std::cout << "Updating contact " << this->last_contact << std::endl;
	else
	{
		this->contacts_size++;
		std::cout << "Adding contact " << this->last_contact << std::endl;
	}
	contact = &this->contacts[this->last_contact];
	*contact = *newContact;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

static std::string getColValue(std::string value)
{
	int spaceAmount;

	spaceAmount = SEARCH_CHAR_AMOUNT - value.size();
	if (spaceAmount < 0)
		value.erase(9).push_back('.');
	else
		value.insert(0, spaceAmount, ' ');
	value.push_back('|');
	return value;
}

void PhoneBook::listContacts(void)
{
	std::cout << "Saved contacts: " << std::endl
			  << "|" << getColValue("Index")
			  << getColValue("First Name")
			  << getColValue("Last Name")
			  << getColValue("Nickname")
			  << std::endl;
	for (int i = 0; i < this->contacts_size; i++)
	{
		std::stringstream index;
		Contact *contact = this->contacts + i;
		index << i;
		std::cout << "|" << getColValue(index.str())
				  << getColValue(contact->getFirstName())
				  << getColValue(contact->getLastName())
				  << getColValue(contact->getNickName())
				  << std::endl;
	}
}

void PhoneBook::searchContact(void)
{
	int 		choice;
	std::string	choice_str;

	choice = -1;
	if (this->contacts_size > 0)
	{
		while (choice < 0 || choice >= this->contacts_size || (choice == 0 && choice_str != "0"))
		{
			choice_str = UserInterface::promptFun("Choose your fighter: ");
			choice = atoi(choice_str.c_str());
		}
		if (!std::cin.eof())
			this->contacts[choice].show();
	}
}