#include "FragTrap.hpp"

void FragTrap::initValues(void)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(void) : ClapTrap()
{
	this->initValues();
	std::cout << this->_name << " FragTrap constructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy)
{
	std::cout << this->_name << " FragTrap copy constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->initValues();
	std::cout << this->_name << " FragTrap string constructor called" << std::endl;
}
void FragTrap::print() const
{
	std::cout << this->_name << " FragTrap has "
			  << this->_hitPoints << " hit points, "
			  << this->_energyPoints << " energy points and "
			  << this->_attackDamage << " attack damage."
			  << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "This is a positive high-fives request from a FragTrap." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &frag)
{
	if (this == &frag)
		return *this;
	this->_name = frag._name;
	this->_hitPoints = frag._hitPoints;
	this->_energyPoints = frag._energyPoints;
	this->_attackDamage = frag._attackDamage;
	std::cout << this->_name << " FragTrap assignation operator called" << std::endl;
	return *this;
}
FragTrap::~FragTrap(void)
{
	std::cout << this->_name << " FragTrap destructor called" << std::endl;
}