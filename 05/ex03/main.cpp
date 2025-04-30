#include <iostream>
#include "Bureaucrat/Bureaucrat.hpp"
#include "Form/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "Form/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "Form/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Intern/Intern.hpp"

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

void tryIntern(Intern &intern)
{
	std::cout << std::endl
			  << "< Intern tries to make forms >" << std::endl;
	try
	{
		AForm *form1 = intern.makeForm("ShrubberyCreationForm", "target1");
		AForm *form2 = intern.makeForm("RobotomyRequestForm", "target2");
		AForm *form3 = intern.makeForm("PresidentialPardonForm", "target3");
		intern.makeForm("an unknown form", "target3");
		std::cout << *form1 << std::endl
				  << *form2 << std::endl
				  << *form3 << std::endl
				  << std::endl;
		(delete form1, delete form2, delete form3);
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
	Intern intern;

	std::cout << "< Initialization >" << std::endl
			  << daenerys << std::endl
			  << form << std::endl
			  << formRobotomy << std::endl
			  << formPresidency << std::endl
			  << intern << std::endl
			  << std::endl;

	tryExec(daenerys, &form);
	tryExec(daenerys, &formRobotomy);
	tryExec(daenerys, &formPresidency);
	tryIntern(intern);
	return 0;
}