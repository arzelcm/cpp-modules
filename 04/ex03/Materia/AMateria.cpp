#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("anon")
{
}

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria(const AMateria &cpy)
{
	*this = cpy;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Using anon Materia on " << target.getName() << std::endl;
}

AMateria &AMateria::operator=(const AMateria &cpy)
{
	if (this == &cpy)
		return (*this);
	this->_type = cpy._type;
	return (*this);
}

AMateria::~AMateria()
{
}