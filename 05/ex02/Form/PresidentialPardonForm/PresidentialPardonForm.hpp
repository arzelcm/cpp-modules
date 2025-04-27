#pragma once
#include "../AForm.hpp"

class PresidentialPardonForm : virtual public AForm
{
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &);
	std::string getTarget() const;
	void execute(Bureaucrat const &executor) const;
	PresidentialPardonForm &operator=(const PresidentialPardonForm &);
	~PresidentialPardonForm();
};