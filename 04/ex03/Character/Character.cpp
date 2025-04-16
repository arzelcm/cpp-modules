#include "Character.hpp"
#include <iostream>

void Character::initValues()
{
	this->_slots_garbage = NULL;
	this->_garbageI = 0;
	for (int i = 0; i < SLOTS_MAX; i++)
		this->_slots[i] = NULL;
}

Character::Character() : _name("Anon")
{
	this->initValues();
}

Character::Character(const Character &cpy)
{
	this->initValues();
	*this = cpy;
}

Character::Character(std::string name) : _name(name)
{
	this->initValues();
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	int i = 0;
	while (i < SLOTS_MAX && this->_slots[i])
		i++;
	if (i < SLOTS_MAX)
		this->_slots[i] = m;
}

AMateria *Character::getMateria(int idx)
{
	if (idx < 0 || idx >= SLOTS_MAX)
		return NULL;
	return this->_slots[idx];
}

void Character::unequip(int idx)
{
	AMateria *materia = this->getMateria(idx);
	if (!materia)
		return;
	this->_slots[idx] = NULL;
	AMateria **newGarbage = new AMateria *[++this->_garbageI];
	int i;
	for (i = 0; i < this->_garbageI - 1; i++)
	{
		newGarbage[i] = this->_slots_garbage[i];
	}
	newGarbage[i] = materia;
	delete[] this->_slots_garbage;
	this->_slots_garbage = newGarbage;
}

void Character::use(int idx, ICharacter &target)
{
	AMateria *materia = this->getMateria(idx);
	if (!materia)
		return;
	materia->use(target);
}

void Character::deleteMaterias()
{
	int i;
	for (i = 0; i < SLOTS_MAX; i++)
	{
		delete this->_slots[i];
		this->_slots[i] = NULL;
	}
	for (i = 0; i < this->_garbageI; i++)
		delete this->_slots_garbage[i];
	(delete[] this->_slots_garbage, this->_slots_garbage = NULL);
	this->_garbageI = 0;
}

void Character::printMaterias() const
{
	std::cout << "Materias for " << this->_name << ":" << std::endl;
	for (int i = 0; i < SLOTS_MAX; i++)
	{
		std::cout << "-";
		if (this->_slots[i])
			std::cout << this->_slots[i]->getType();
		else
			std::cout << "NULL";
		std::cout << std::endl;
	}
}

Character &Character::operator=(const Character &cpy)
{
	if (this == &cpy)
		return (*this);
	this->_name = cpy._name;
	this->deleteMaterias();
	for (int i = 0; i < SLOTS_MAX; i++)
	{
		if (cpy._slots[i])
			this->_slots[i] = cpy._slots[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	this->deleteMaterias();
}