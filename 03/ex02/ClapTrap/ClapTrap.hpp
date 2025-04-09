#pragma once
#include <iostream>

class ClapTrap
{
protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
	bool canPerform() const;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &cpy);
	std::string getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;
	ClapTrap &operator=(const ClapTrap &clap);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void print() const;
	~ClapTrap(void);
};