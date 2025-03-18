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

std::string Contact::getFirstName(void)
{
	return this->firstName;
}

std::string Contact::getLastName(void)
{
	return this->lastName;
}

std::string Contact::getNickName(void)
{
	return this->nickName;
}

std::string Contact::getPhoneNumber(void)
{
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret(void)
{
	return this->darkestSecret;
}

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}
void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}
void Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
}
void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}
