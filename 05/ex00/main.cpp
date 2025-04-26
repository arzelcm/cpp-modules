#include <iostream>
#include "Bureaucrat/Bureaucrat.hpp"

int main(void)
{
	std::cout << "< Instantiate daenerys >" << std::endl;
	// Bureaucrat daenerys("Daenerys");
	Bureaucrat daenerys("Daenerys de la Tormenta de la casa Targaryen, La Primera de su Nombre, Reina de los Ándalos, los Rhoynar y los Primeros Hombres, Señora de los Siete Reinos y Protectora del Reino, Khaleesi del Gran Mar de la Hierba, Señora de Rocadragón y Reina de Meereen", 134);
	std::cout << daenerys << std::endl;
	std::cout << std::endl << "< Set grade 200 >" << std::endl;
	try
	{
		daenerys.setGrade(200);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		daenerys.print();
	}
	std::cout << std::endl << "< Set grade 0 >" << std::endl;
	try
	{
		daenerys.setGrade(0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		daenerys.print();
	}
	std::cout << std::endl << "< Set grade 20 >" << std::endl;
	try
	{
		daenerys.setGrade(20);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		daenerys.print();
	}
	daenerys.print();
	std::cout << std::endl << "< Set grade 1 and increment it >" << std::endl;
	try
	{
		daenerys.setGrade(1);
		daenerys.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		daenerys.print();
	}
	std::cout << std::endl << "< Set grade 150 and decrement it >" << std::endl;
	try
	{
		daenerys.setGrade(150);
		daenerys.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		daenerys.print();
	}

	return 0;
}