#include <iostream>
#include "Bureaucrat/Bureaucrat.hpp"

void trySign(Bureaucrat &buro, Form &form)
{
	std::cout << std::endl
			  << "< " << buro.getName() << " try sign " << form.getName() << " >" << std::endl;
	try
	{
		buro.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	Bureaucrat daenerys("Daenerys", 5);
	Form model23("Model23", 2, 1);
	Form model25("Model25", 5, 1);
	Form model26("Model26", 8, 1);
	std::cout << daenerys << std::endl
			  << model23 << std::endl
			  << model25 << std::endl
			  << std::endl;
	std::cout << std::endl
			  << "< Try instantiate form out of bounds  >" << std::endl;
	try
	{
		Form model1("Model1", B_GRADE_MAX - 1, 23);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	trySign(daenerys, model23);
	trySign(daenerys, model25);
	trySign(daenerys, model26);
	return 0;
}