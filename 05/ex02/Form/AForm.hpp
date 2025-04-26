#pragma once
#include <iostream>
#include "Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
	void initValues();

public:
	AForm();
	AForm(const AForm &);
	AForm(std::string name, int signGrade, int execGrade);
	const std::string &getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat &);
	void checkPerms(const Bureaucrat &b, int grade) const;
	virtual void execute(Bureaucrat const &) const = 0;
	AForm &operator=(const AForm &);
	virtual ~AForm();
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw() { return "grade too high."; };
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw() { return "grade too low."; };
	};
};

std::ostream &operator<<(std::ostream &, const AForm &);