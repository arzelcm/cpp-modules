#include "DiamondTrap.hpp"

void DiamondTrap::initValues(void)
{
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap()
{
	this->_name = "Anon";
	this->initValues();
	std::cout << this->_name << " DiamondTrap constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &cpy) : ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy)
{
	std::cout << this->_name << " DiamondTrap copy constructor called" << std::endl;
	*this = cpy;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name)
{
	this->initValues();
	std::cout << this->_name << " DiamondTrap string constructor called" << std::endl;
}

std::string DiamondTrap::getName() const
{
	return this->_name;
}

void DiamondTrap::print() const
{
	std::cout << this->_name << " DiamondTrap has "
			  << this->_hitPoints << " hit points, "
			  << this->_energyPoints << " energy points and "
			  << this->_attackDamage << " attack damage."
			  << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "Hi! I'm a DiamondTrap, my name is " << this->_name
			  << " and my ClapTrap name is " << this->ClapTrap::_name
			  << "."
			  << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &frag)
{
	if (this == &frag)
		return *this;
	this->_name = frag._name;
	this->_hitPoints = frag._hitPoints;
	this->_energyPoints = frag._energyPoints;
	this->_attackDamage = frag._attackDamage;
	std::cout << this->_name << " DiamondTrap assignation operator called" << std::endl;
	return *this;
}
DiamondTrap::~DiamondTrap(void)
{
	std::cout << this->_name << " DiamondTrap destructor called" << std::endl;
}