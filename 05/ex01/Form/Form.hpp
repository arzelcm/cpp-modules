#pragma once
#include <iostream>
#include "Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
	void initValues();

public:
	Form();
	Form(const Form &);
	Form(std::string name, int signGrade, int execGrade);
	const std::string &getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat &);
	Form &operator=(const Form &);
	~Form();
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw() { return "grade too high."; };
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw() { return "grade too low."; };
	};
};

std::ostream &operator<<(std::ostream &, const Form &);