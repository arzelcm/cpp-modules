#include "MateriaSource.hpp"
#include <iostream>

void MateriaSource::initValues()
{
	for (int i = 0; i < MAX_KNOWLEDGE; i++)
	{
		this->_knownMaterias[i] = NULL;
	}
	this->_materiasI = 0;
}

void MateriaSource::deleteKnownMaterias()
{
	for (int i = 0; i < this->_materiasI; i++)
	{
		delete this->_knownMaterias[i];
		this->_knownMaterias[i] = NULL;
	}
}

MateriaSource::MateriaSource()
{
	this->initValues();
}

MateriaSource::MateriaSource(const MateriaSource &cpy)
{
	*this = cpy;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia || this->_materiasI == MAX_KNOWLEDGE)
		return;
	this->_knownMaterias[this->_materiasI++] = materia;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int i;
	for (i = 0;
		 i < this->_materiasI && this->_knownMaterias[i] && this->_knownMaterias[i]->getType() != type;
		 i++)
		(void)NULL;
	if (i < this->_materiasI && this->_knownMaterias[i])
		return this->_knownMaterias[i]->clone();
	return NULL;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &cpy)
{
	if (this == &cpy)
		return (*this);
	this->deleteKnownMaterias();
	this->_materiasI = cpy._materiasI;
	for (int i = 0; i < this->_materiasI; i++)
		this->_knownMaterias[i] = cpy._knownMaterias[i]->clone();
	return (*this);
}

MateriaSource::~MateriaSource()
{
	this->deleteKnownMaterias();
}
