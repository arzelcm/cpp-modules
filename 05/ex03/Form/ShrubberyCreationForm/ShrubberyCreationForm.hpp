#pragma once
#include "../AForm.hpp"

class ShrubberyCreationForm : virtual public AForm
{
private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	std::string getTarget() const;
	void execute(Bureaucrat const &executor) const;
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
	~ShrubberyCreationForm();
};