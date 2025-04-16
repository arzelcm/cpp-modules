#pragma once
#include <string>
#include "Character/ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria&);
	AMateria &operator=(const AMateria&);
	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
	virtual ~AMateria();
};