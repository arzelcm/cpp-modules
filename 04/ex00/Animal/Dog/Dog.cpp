#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog &dog) : Animal("Dog")
{
	*this = dog;
	std::cout << "Dog copy constructor called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "woof, woof" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this == &dog)
		return *this;
	this->_type = dog._type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}