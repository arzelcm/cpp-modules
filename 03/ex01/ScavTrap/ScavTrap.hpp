#pragma once
#include "ClapTrap/ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool _gateKeeper;

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &cpy);
	bool getGateKeeper(void) const;
	ScavTrap &operator=(const ScavTrap &scav);
	void attack(const std::string &target);
	void print() const;
	void guardGate(void);
	~ScavTrap();
};