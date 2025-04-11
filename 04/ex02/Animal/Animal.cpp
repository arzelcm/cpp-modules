#include "Animal.hpp"

Animal::Animal() : _type("Unknown")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal &animal)
{
	*this = animal;
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal type constructor called for " << this->_type << "." << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}

Animal &Animal::operator=(const Animal &animal)
{
	if (this == &animal)
		return *this;
	this->_type = animal._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}