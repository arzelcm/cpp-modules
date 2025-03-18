#include <iostream>
#include <sstream>
#include "PhoneBook.hpp"
#include "UserInterface/UserInterface.hpp"

PhoneBook::PhoneBook(void)
{
	this->contacts_size = 0;
	return ;
}

void	PhoneBook::addContact(Contact *newContact)
{
	Contact *contact;
	if (this->contacts_size >= PHONE_BOOK_MAX_CONTACTS)
		std::cout << "Updating contact " << --this->contacts_size << std::endl;
	else
		std::cout << "Adding contact " << this->contacts_size << std::endl;
	contact = &this->contacts[this->contacts_size++];
	*contact = *newContact;

}

PhoneBook::~PhoneBook(void)
{
	return ;
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
	int	choice;

	choice = -1;
	if (this->contacts_size > 0)
	{
		while (choice < 0 || choice >= this->contacts_size)
			choice = atoi(UserInterface::promptFun("Choose your fighter: ").c_str());
		if (!std::cin.eof())
			this->contacts[choice].show();
	}
}