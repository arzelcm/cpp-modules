#pragma once

#define B_GRADE_MAX 1
#define B_GRADE_MIN 150
#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade); // Throws exceptions.
	Bureaucrat(const Bureaucrat &);
	int getGrade() const;
	void setGrade(int grade); // Throws exceptions.
	std::string getName() const;
	void incrementGrade(); // Throws exceptions.
	void decrementGrade(); // Throws exceptions.
	void print();
	Bureaucrat &operator=(const Bureaucrat &);
	~Bureaucrat();
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw() {return "!Error! Grade too high.";};
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw() {return "!Error! Grade too low.";};
	};
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);