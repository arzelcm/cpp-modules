#include <iostream>
#include "ClapTrap/ClapTrap.hpp"

void attack(ClapTrap &attacker, ClapTrap &victim)
{
	attacker.attack(victim.getName());
	victim.takeDamage(attacker.getAttackDamage());
}

int main(void)
{
	ClapTrap trap("attacker");
	ClapTrap trap2("victim");
	ClapTrap trap3 = trap2;
	trap.print();
	while (trap.getEnergyPoints() != 0)
		attack(trap, trap2);
	attack(trap, trap2);
	trap.takeDamage(4);
	trap.beRepaired(4);
	trap.print();
	return 0;
}