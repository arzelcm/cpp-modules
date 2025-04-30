#pragma once
#include "Form/AForm.hpp"
#define KNOWN_FORMS 3

class Intern
{
private:
	static std::string _calls[KNOWN_FORMS];
	static AForm *(*_builders[KNOWN_FORMS])(std::string target);

public:
	Intern();
	Intern(const Intern &);
	AForm *makeForm(std::string call, std::string target) const;
	Intern &operator=(const Intern &);
	~Intern();
};

std::ostream &operator<<(std::ostream &, const Intern &);