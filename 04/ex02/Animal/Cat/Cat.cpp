#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
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
	this->_brain = new Brain(*cat._brain);
	return *this;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called." << std::endl;
}