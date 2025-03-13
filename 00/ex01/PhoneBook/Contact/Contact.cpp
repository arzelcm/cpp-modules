#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void Contact::show(void)
{
	std::cout << "First name: " << this->firstName << std::endl
			  << "Last name: " << this->lastName << std::endl
			  << "Nick name: " << this->nickName << std::endl
			  << "Phone number: " << this->phoneNumber << std::endl
			  << "Darkest secret: " << this->darkestSecret << std::endl;
}