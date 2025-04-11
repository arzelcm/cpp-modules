#pragma once
#include "Animal/Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &);
	void makeSound() const;
	Dog &operator=(const Dog &);
	~Dog();
};