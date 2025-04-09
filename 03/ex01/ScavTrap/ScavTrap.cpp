#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _gateKeeper(false)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << this->_name << " ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _gateKeeper(false)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << this->_name << " ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy)
{
	this->_gateKeeper = cpy._gateKeeper;
	std::cout << this->_name << " ScavTrap copy constructor called" << std::endl;
}

bool ScavTrap::getGateKeeper(void) const
{
	return this->_gateKeeper;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scav)
{
	if (this == &scav)
		return *this;
	this->_name = scav._name;
	this->_gateKeeper = scav._gateKeeper;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->canPerform())
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attackDamage << " points of damage!"
				  << std::endl;
	}
	else
	{
		std::cout << "Cannot attack! ";
		this->print();
	}
}

void ScavTrap::print() const
{
	std::cout << this->_name << " ScavTrap has "
			  << this->_hitPoints << " hit points, "
			  << this->_energyPoints << " energy points, "
			  << this->_attackDamage << " attack damage and"
			  << this->_gateKeeper << " gate keeper mode."
			  << std::endl;
}

void ScavTrap::guardGate(void)
{
	this->_gateKeeper = true;
	std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->_name << " ScavTrap destructor called" << std::endl;
}
