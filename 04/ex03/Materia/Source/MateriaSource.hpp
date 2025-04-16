#pragma once
#include "IMateriaSource.hpp"
#define MAX_KNOWLEDGE 4

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_knownMaterias[MAX_KNOWLEDGE];
	void initValues();
	void deleteKnownMaterias();
	int _materiasI;

public:
	MateriaSource();
	MateriaSource(const MateriaSource &);
	virtual void learnMateria(AMateria *);
	virtual AMateria *createMateria(std::string const &type);
	MateriaSource &operator=(const MateriaSource &);
	~MateriaSource();
};