#include "AForm.hpp"

void AForm::initValues()
{
}

AForm::AForm() : _name("Anon"), _signed(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(const AForm &cpy) : _name(cpy._name),
								 _signGrade(cpy._signGrade),
								 _execGrade(cpy._execGrade)
{
	*this = cpy;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name),
															   _signed(false),
															   _signGrade(signGrade),
															   _execGrade(execGrade)
{
	if (this->_signGrade < B_GRADE_MAX || this->_execGrade < B_GRADE_MAX)
		throw GradeTooHighException();
	else if (this->_signGrade > B_GRADE_MIN || this->_execGrade > B_GRADE_MIN)
		throw GradeTooLowException();
}

const std::string &AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecGrade() const
{
	return this->_execGrade;
}

void AForm::beSigned(const Bureaucrat &b)
{
	this->checkPerms(b, this->_signGrade);
	this->_signed = true;
}

void AForm::checkPerms(const Bureaucrat &b, int grade) const
{
	if (b.getGrade() > grade)
		throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &cpy)
{
	if (this != &cpy)
		this->_signed = cpy._signed;
	return *this;
}

AForm::~AForm()
{
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	return os
		   << form.getName()
		   << " AForm -> { signed " << form.getSigned()
		   << ", signGrade: " << form.getSignGrade()
		   << ", execGrade: " << form.getExecGrade()
		   << " }";
}
