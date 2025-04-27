#pragma once
#include "../AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &);
	std::string getTarget() const;
	void execute(Bureaucrat const &executor) const;
	RobotomyRequestForm &operator=(const RobotomyRequestForm &);
	~RobotomyRequestForm();
};