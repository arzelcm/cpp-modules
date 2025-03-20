#pragma once
#include <iostream>
#include "Weapon/Weapon.hpp"

class HumanA
{
private:
	Weapon &weapon;
	std::string name;

public:
	HumanA(std::string name, Weapon &weapon);
	void setWeapon(Weapon &weapon);
	void attack(void);
};