#pragma once
#include "../AMateria.hpp"
#define CURE_TYPE "cure"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &);
	virtual Cure *clone() const;
	virtual void use(ICharacter &target);
	Cure &operator=(const Cure &);
	~Cure();
};