#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria(ICE_TYPE)
{
}

Ice::Ice(const Ice &cpy) : AMateria(ICE_TYPE)
{
	*this = cpy;
}

Ice *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice &Ice::operator=(const Ice &cpy)
{
	if (this == &cpy)
		return *this;
	this->_type = cpy._type;
	return *this;
}

Ice::~Ice()
{
}