#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "Anonymous";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

std::string Zombie::getName(void)
{
	return this->name;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name	<< ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroying " << this->name << std::endl;
}