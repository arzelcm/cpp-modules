#include "Form.hpp"

void Form::initValues()
{
}

Form::Form() : _name("Anon"), _signed(false), _signGrade(150), _execGrade(150)
{
}

Form::Form(const Form &cpy) : _name(cpy._name),
							  _signGrade(cpy._signGrade),
							  _execGrade(cpy._execGrade)
{
	*this = cpy;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name),
															 _signed(false),
															 _signGrade(signGrade),
															 _execGrade(execGrade)
{
	if (this->_signGrade < B_GRADE_MAX || this->_execGrade < B_GRADE_MAX)
		throw GradeTooHighException();
	else if (this->_signGrade > B_GRADE_MIN || this->_execGrade > B_GRADE_MIN)
		throw GradeTooLowException();
}

const std::string &Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecGrade() const
{
	return this->_execGrade;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	else
		this->_signed = true;
}

Form &Form::operator=(const Form &cpy)
{
	if (this != &cpy)
		this->_signed = cpy._signed;
	return *this;
}

Form::~Form()
{
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	return os
		   << form.getName()
		   << " Form -> { signed " << form.getSigned()
		   << ", signGrade: " << form.getSignGrade()
		   << ", execGrade: " << form.getExecGrade()
		   << " }";
}
