#pragma once
#include <iostream>

class Animal
{
protected:
	std::string _type;

public:
	Animal();
	Animal(const Animal &);
	Animal(std::string);
	virtual void makeSound() const;
	std::string getType() const;
	Animal &operator=(const Animal &);
	virtual ~Animal();
};