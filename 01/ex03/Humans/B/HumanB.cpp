#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void HumanB::attack(void)
{
	std::cout << this->name << " attacks with their ";
	if (this->weapon)
		std::cout << this->weapon->getType() << std::endl;
	else
		std::cout << "no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
