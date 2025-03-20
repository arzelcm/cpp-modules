#include "Weapon.hpp"

Weapon::Weapon(void)
{
	this->type = "unknown weapon";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string Weapon::getType(void)
{
	return this->type;
}
void Weapon::setType(std::string type)
{
	this->type = type;
}