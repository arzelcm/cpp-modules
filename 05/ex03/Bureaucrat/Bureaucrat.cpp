#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Anon")
{
	this->setGrade(150);
}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
	this->setGrade(150);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name)
{
	*this = cpy;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < B_GRADE_MAX)
		throw GradeTooHighException();
	else if (grade > B_GRADE_MIN)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

void Bureaucrat::incrementGrade()
{
	this->setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	this->setGrade(this->_grade + 1);
}

void Bureaucrat::print() const
{
	std::cout << *this << std::endl;
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << *this << " couldn't execute " << form << " because " << e.what() << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
	if (this == &cpy)
		return *this;
	else
	{
		this->_grade = cpy._grade;
		return *this;
	}
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureau)
{
	return os
		   << bureau.getName()
		   << " Bureaucrat -> { grade: " << bureau.getGrade()
		   << " }";
}