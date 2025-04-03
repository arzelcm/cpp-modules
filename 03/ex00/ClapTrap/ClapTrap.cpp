#include "ClapTrap/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Anon"),
					   _hitPoints(10),
					   _energyPoints(10),
					   _attackDamage(0)
{
	std::cout << this->_name << " default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name),
									   _hitPoints(10),
									   _energyPoints(10),
									   _attackDamage(0)
{
	std::cout << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy) : _name(cpy.getName()),
										  _hitPoints(cpy.getHitPoints()),
										  _energyPoints(cpy.getEnergyPoints()),
										  _attackDamage(cpy.getAttackDamage())
{
	std::cout << this->_name << " copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clap)
{
	if (this == &clap)
		return *this;
	this->_name = clap.getName();
	this->_hitPoints = clap.getHitPoints();
	this->_energyPoints = clap.getEnergyPoints();
	this->_attackDamage = clap.getAttackDamage();
	return *this;
}

std::string ClapTrap::getName() const
{
	return this->_name;
}

int ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

bool ClapTrap::canPerform() const
{
	return this->_energyPoints > 0 && this->_hitPoints > 0;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->canPerform())
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attackDamage << " points of damage!"
				  << std::endl;
	}
	else
	{
		std::cout << "Cannot attack! ";
		this->print();
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->canPerform())
	{
		this->_energyPoints--;
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name
				  << " has been repaired, now has "
				  << this->_hitPoints << " hit points."
				  << std::endl;
	}
	else
	{
		std::cout << "Cannot repair! ";
		this->print();
	}
}

void ClapTrap::print() const
{
	std::cout << "ClapTrap " << this->_name << " has "
			  << this->_hitPoints << " hit points, "
			  << this->_energyPoints << " energy points and "
			  << this->_attackDamage << " attack damage."
			  << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << this->_name << " destructor called" << std::endl;
}