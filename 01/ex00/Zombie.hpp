#pragma once

#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);
	std::string getName(void);
	void setName(std::string name);
};

Zombie *newZombie(std::string name);

void randomChump(std::string name);
