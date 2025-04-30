#include "Intern.hpp"
#include "Form/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "Form/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "Form/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include <iostream>

std::string Intern::_calls[KNOWN_FORMS] = {
	"ShrubberyCreationForm",
	"RobotomyRequestForm",
	"PresidentialPardonForm"
};

static AForm *newShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *newRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm *newPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *(*Intern::_builders[KNOWN_FORMS])(std::string target) = {
	newShrubberyCreationForm,
	newRobotomyRequestForm,
	newPresidentialPardonForm,
};

Intern::Intern()
{
}

Intern::Intern(const Intern &cpy)
{
	*this = cpy;
}

AForm *Intern::makeForm(std::string call, std::string target) const
{
	bool found = false;
	int i;
	for (i = 0; i < KNOWN_FORMS && !found; i++)
		found = call == Intern::_calls[i];
	if (found)
	{
		AForm *form = this->_builders[i - 1](target);
		std::cout << "Intern creates " << *form << std::endl;
		return form;
	}
	else
	{
		std::cout << "Intern couldn't create " << call << "." << std::endl;
		return NULL;
	}
}

Intern &Intern::operator=(const Intern &)
{
	return *this;
}

Intern::~Intern()
{
}

std::ostream &operator<<(std::ostream &os, const Intern &intern)
{
	(void)intern;
	return os << "Intern -> { knownForms: " << KNOWN_FORMS << " }";
}
