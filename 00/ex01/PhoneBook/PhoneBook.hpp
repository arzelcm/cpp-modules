#pragma once
#include "Contact/Contact.hpp"
#define PHONE_BOOK_MAX_CONTACTS 8
#define SEARCH_COLUMNS 4
#define SEARCH_CHAR_AMOUNT 10

class PhoneBook
{
private:
	Contact contacts[PHONE_BOOK_MAX_CONTACTS];
	int contacts_size;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(Contact *newContact);
	void listContacts(void);
	void searchContact();
};