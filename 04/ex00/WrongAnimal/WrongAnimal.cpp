#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Wrong")
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	*this = wrongAnimal;
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal type constructor called for " << this->_type << "." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong sound." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
	if (this == &wrongAnimal)
		return *this;
	this->_type = wrongAnimal._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}