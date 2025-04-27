#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45),
															   _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy)
{
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->checkPerms(executor, this->getExecGrade());
	std::cout << this->getName() << ": brrrrrrZZZZZZzzzzzzz... whirrrr... clank clank!" << std::endl;
	std::srand(std::time(nullptr));
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomization of " << this->_target << " failed." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	if (this != &cpy)
		this->_target = cpy._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
