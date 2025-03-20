#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie *zombieFoo;

	std::cout << "Hello world ;)" << std::endl;
	zombieFoo = newZombie("heap");
	zombieFoo->announce();
	delete zombieFoo;
	randomChump("stack");
	return 0;
}
