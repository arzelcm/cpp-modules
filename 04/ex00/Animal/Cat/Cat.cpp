#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat &cat) : Animal("Cat")
{
	*this = cat;
	std::cout << "Cat copy constructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miiiaaaaaaaauuuuuuuu" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this == &cat)
		return *this;
	this->_type = cat._type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}