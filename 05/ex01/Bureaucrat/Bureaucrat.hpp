#pragma once

#define B_GRADE_MAX 1
#define B_GRADE_MIN 150
#include <string>
#include <iostream>
#include "Form/Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &);
	int getGrade() const;
	void setGrade(int grade);
	std::string getName() const;
	void incrementGrade();
	void decrementGrade();
	void print();
	void signForm(Form &) const;
	Bureaucrat &operator=(const Bureaucrat &);
	~Bureaucrat();
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw() { return "!Error! Grade too high."; };
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw() { return "!Error! Grade too low."; };
	};
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);