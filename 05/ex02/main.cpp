#include <iostream>
#include "Bureaucrat/Bureaucrat.hpp"
#include "Form/ShrubberyCreationForm/ShrubberyCreationForm.hpp"

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
		form->execute(buro);
		// buro.execForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	Bureaucrat daenerys("Daenerys", 1);
	ShrubberyCreationForm form("home");
	std::cout << daenerys << std::endl
			  << form << std::endl
			  << std::endl;
	tryExec(daenerys, &form);
	// std::cout << std::endl
	// 		  << "< Try instantiate form out of bounds  >" << std::endl;
	// try
	// {
	// 	Form model1("Model1", B_GRADE_MAX - 1, 23);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }

	// trySign(daenerys, model23);
	// trySign(daenerys, model25);
	// trySign(daenerys, model26);
	return 0;
}