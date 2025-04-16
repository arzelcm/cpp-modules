#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &cpy) : AMateria("cure")
{
	*this = cpy;
}

Cure *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure &Cure::operator=(const Cure &cpy)
{
	if (this == &cpy)
		return *this;
	this->_type = cpy._type;
	return (*this);
}

Cure::~Cure()
{
}