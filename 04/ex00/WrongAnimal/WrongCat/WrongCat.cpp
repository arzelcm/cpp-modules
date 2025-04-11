#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal("WrongCat")
{
	*this = wrongCat;
	std::cout << "WrongCat copy constructor called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong miiiaaaaaaaauuuuuuuu" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
	if (this == &wrongCat)
		return *this;
	this->_type = wrongCat._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}