#pragma once
#include "../AForm.hpp"

class ShrubberyCreationForm : virtual public AForm
{
private:
	std::string _target; // TTODO: Implement getter

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	void execute(Bureaucrat const &executor) const;
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
	~ShrubberyCreationForm();
};