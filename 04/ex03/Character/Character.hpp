#pragma once
#include "ICharacter.hpp"
#include "Materia/AMateria.hpp"
#define SLOTS_MAX 4

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_slots[SLOTS_MAX];
	AMateria **_slots_garbage;
	int _garbageI;
	void initValues();
	AMateria *getMateria(int idx);
	void deleteMaterias();

public:
	Character();
	Character(std::string);
	Character(const Character &);
	virtual std::string const &getName() const;
	virtual void equip(AMateria *);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
	virtual void printMaterias() const;
	Character &operator=(const Character &);
	~Character();
};