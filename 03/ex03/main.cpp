#include <iostream>
#include "ClapTrap/ClapTrap.hpp"
#include "ScavTrap/ScavTrap.hpp"
#include "FragTrap/FragTrap.hpp"
#include "DiamondTrap/DiamondTrap.hpp"

void attack(ScavTrap &attacker, ClapTrap &victim)
{
	attacker.attack(victim.getName());
	victim.takeDamage(attacker.getAttackDamage());
}

int main(void)
{
	ClapTrap trinity = ClapTrap("Trinity");
	ClapTrap xanax = ClapTrap("Xanax");
	ClapTrap antares = ClapTrap("Antares");

	trinity.print();
	xanax.print();
	antares.print();

	trinity.attack("Xanax");
	xanax.attack("Antares");
	xanax.takeDamage(4);
	antares.takeDamage(12);

	trinity.print();
	xanax.print();
	antares.print();

	xanax.beRepaired(3);
	antares.beRepaired(4);
	antares.attack("Trinity");

	trinity.print();
	xanax.print();
	antares.print();

	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);

	trinity.print();
	xanax.print();
	antares.print();

	ScavTrap cake = ScavTrap("Cake");

	cake.print();

	cake.attack("xanax");
	cake.guardGate();

	FragTrap apple = FragTrap("Apple");

	apple.print();

	apple.attack("xanax");
	apple.highFivesGuys();

	DiamondTrap sand = DiamondTrap("Sand");

	sand.print();

	sand.attack("xanax");
	sand.whoAmI();

	return 0;
}