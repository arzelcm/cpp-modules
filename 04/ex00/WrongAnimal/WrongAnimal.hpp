#pragma once
#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &);
	WrongAnimal(std::string);
	virtual void makeSound() const;
	std::string getType() const;
	WrongAnimal &operator=(const WrongAnimal &);
	virtual ~WrongAnimal();
};