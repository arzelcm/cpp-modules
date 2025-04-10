#pragma once
#include "FragTrap/FragTrap.hpp"
#include "ScavTrap/ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
	void initValues(void);

public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &cpy);
	std::string getName() const;
	void print() const;
	void whoAmI();
	DiamondTrap &operator=(const DiamondTrap &frag);
	~DiamondTrap(void);
};