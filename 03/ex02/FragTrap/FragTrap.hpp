#pragma once
#include "ClapTrap/ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	void initValues(void);

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &cpy);
	void print() const;
	void highFivesGuys(void);
	FragTrap &operator=(const FragTrap &frag);
	~FragTrap(void);
};