#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;
	int zombiesAmount;

	zombiesAmount = 4;
	zombie = zombieHorde(zombiesAmount, "Foo");
	for (int i = 0; i < zombiesAmount; i++)
		zombie[i].announce();
	delete[] zombie;
	return 0;
}
