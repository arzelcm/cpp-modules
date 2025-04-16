#include <iostream>
#include "Materia/Ice/Ice.hpp"
#include "Materia/Source/IMateriaSource.hpp"
#include "Materia/Source/MateriaSource.hpp"
#include "Materia/Cure/Cure.hpp"
#include "Character/Character.hpp"

int main(void)
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->printMaterias();
	ICharacter *bob = new Character("bob");
	bob->equip(new Ice());
	bob->equip(new Cure());
	bob->equip(new Cure());
	bob->equip(new Cure());
	bob->use(0, *me);
	bob->use(1, *me);
	bob->use(2, *me);
	bob->use(444, *me);
	bob->printMaterias();
	bob->unequip(3);
	bob->printMaterias();
	ICharacter *almansor = new Character((Character&) *me);
	almansor->printMaterias();
	(Character&) *almansor = (Character&) *bob;
	almansor->printMaterias();
	delete almansor;
	delete bob;
	delete me;
	delete src;
	return 0;
}