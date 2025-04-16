#pragma once
#include "../AMateria.hpp"
#define ICE_TYPE "ice"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &);
	virtual Ice *clone() const;
	virtual void use(ICharacter &target);
	Ice &operator=(const Ice &);
	~Ice();
};