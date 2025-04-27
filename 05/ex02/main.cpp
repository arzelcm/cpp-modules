#include <iostream>
#include "Bureaucrat/Bureaucrat.hpp"
#include "Form/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "Form/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "Form/PresidentialPardonForm/PresidentialPardonForm.hpp"

void trySign(Bureaucrat &buro, AForm *form)
{
	std::cout << std::endl
			  << "< " << buro.getName() << " tries to sign " << form->getName() << " >" << std::endl;
	try
	{
		buro.signForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void tryExec(Bureaucrat &buro, AForm *form)
{
	std::cout << std::endl
			  << "< " << buro.getName() << " tries to execute " << form->getName() << " >" << std::endl;
	try
	{
		buro.executeForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	Bureaucrat daenerys("Daenerys", 150);
	ShrubberyCreationForm form("home");
	RobotomyRequestForm formRobotomy("target");
	PresidentialPardonForm formPresidency("target");
	std::cout << "< Initialization >" << std::endl
			  << daenerys << std::endl
			  << form << std::endl
			  << formRobotomy << std::endl
			  << formPresidency << std::endl
			  << std::endl;
	tryExec(daenerys, &form);
	tryExec(daenerys, &formRobotomy);
	tryExec(daenerys, &formPresidency);
	return 0;
}